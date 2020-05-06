#!/usr/bin/env python3

import os

EXCLUDE_DIRS = ( "../source/external/", "../source/opengl/", "../source/utility/" )
SOURCE_DIR = "../source/"

in_block_comment = False

total_code_count = 0
total_comment_count = 0
total_blank_count = 0
total_line_count = 0

def print_formatted (file, code, comments, blank, total):
    print("| ", end="")
    print(file.ljust(filename_padding), end="")
    print(" | ", end="")
    print(code.rjust(10), end="")
    print(" | ", end="")
    print(comments.rjust(10), end="")
    print(" | ", end="")
    print(blank.rjust(10), end="")
    print(" | ", end="")
    print(total.rjust(10), end="")
    print(" |")

def line_is_code (line):
    global in_block_comment
    line_length = len(line)
    is_code = False
    i = 0
    while i < line_length:
        state_change = False
        if line[i] == "/" and line[i+1] == "*":
            if not in_block_comment:
                in_block_comment = True
                state_change = True
                i += 2
        elif line[i] == "*" and line[i+1] == "/":
            if in_block_comment:
                in_block_comment = False
                state_change = True
                i += 2
        if i >= line_length:
            break
        if not in_block_comment and not line[i].isspace():
            is_code = True
        if state_change:
            i -= 1
        i += 1

    return is_code

# Determine the longest file name so we can pad the output with spaces.
filename_padding = 5 # Length of the world 'TOTAL'.
for subdir, dirs, files, in os.walk(SOURCE_DIR):
    for file in files:
        filename = os.path.join(subdir, file)
        filename = filename.replace("\\","/")
        if not filename.startswith(EXCLUDE_DIRS):
            if len(filename) > filename_padding:
                filename_padding = len(filename)

print_formatted("FILE", "CODE", "COMMENTS", "BLANK", "TOTAL")

# Determine the number of code lines for each of the source code files.
for subdir, dirs, files, in os.walk(SOURCE_DIR):
    for file in files:
        filename = os.path.join(subdir, file)
        filename = filename.replace("\\","/")

        if not filename.startswith(EXCLUDE_DIRS):
            code_count = 0
            comment_count = 0
            blank_count = 0
            line_count = 0

            if filename.lower().endswith((
                ".h", ".hh", ".hpp", ".hxx", ".h++",
                ".c", ".cc", ".cpp", ".cxx", ".c++", ".cp",
                ".inl", ".ipp", ".hint")):
                with open(filename) as f:
                    for line in f:
                        line = line.lstrip()
                        line_length = len(line)

                        if in_block_comment:
                            block_comment_exit_pos = 0
                            for i in range(0, line_length-1):
                                if line[i] == "*" and line[i+1] == "/":
                                    in_block_comment = False
                                    block_comment_exit_pos = i+2
                                    break
                            if in_block_comment:
                                comment_count += 1
                            else:
                                if block_comment_exit_pos < line_length:
                                    if line_is_code(line[block_comment_exit_pos:]):
                                        code_count += 1
                                        continue
                                comment_count += 1
                        else:
                            if not line:
                                blank_count += 1
                            elif line[0] == "/" and line[1] == "/":
                                comment_count += 1
                            else:
                                if line_is_code(line):
                                    code_count += 1
                                else:
                                    comment_count += 1

                line_count = code_count + comment_count + blank_count

                total_code_count += code_count
                total_comment_count += comment_count
                total_blank_count += blank_count
                total_line_count += line_count

                print_formatted(filename,
                    str(code_count),
                    str(comment_count),
                    str(blank_count),
                    str(line_count))

print_formatted("TOTAL",
    str(total_code_count),
    str(total_comment_count),
    str(total_blank_count),
    str(total_line_count))
