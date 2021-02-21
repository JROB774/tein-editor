#!/usr/bin/env python3

import sys
import os

from argparse import ArgumentParser

parser = ArgumentParser(description="Package a folder into the GPAK file format.")
parser.add_argument("input", help="the input folder to package as the GPAK")
parser.add_argument("output", help="the name and location of the resulting GPAK")
args = parser.parse_args()

RESOURCES_DIR = args.input
OUTPUT_GPAK = args.output

index = bytearray()
files = bytearray()

index_count = 0

def int_to_bytes (val, num_bytes):
    return [(val & (0xff << pos * 8)) >> pos * 8 for pos in range(num_bytes)]

for dir_name, subdir_list, file_list in os.walk(RESOURCES_DIR):
    for file_name in file_list:
        index_count = index_count + 1
        full_path = dir_name + "/" + file_name

        full_path = full_path.replace('\\', '/')
        full_path = full_path.lower()

        if full_path.startswith(RESOURCES_DIR):
            key_path = full_path[len(RESOURCES_DIR)+1:]

        index.extend(int_to_bytes(len(key_path), 2))
        index.extend(bytearray(key_path, "ascii"))
        with open(full_path, mode='rb') as file:
            file_content = file.read()
            length = len(file_content)

            print("Packing " + key_path + " (" + str(length) + " bytes)")
            index.extend(int_to_bytes(length, 4))

            files.extend(file_content)

gpak = open(OUTPUT_GPAK, "wb")
gpak.write(bytearray(int_to_bytes(index_count, 4)))
gpak.write(index)
gpak.write(files)
