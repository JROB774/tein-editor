#!/usr/bin/env python3

import datetime

MANIFEST_FILE = "resource/resources/.manifest"
VERSION_FILE = "source/version.hpp"

AUTHOR  = "JoshuaRobertson"
PROJECT = "TEIN"
APPNAME = "TheEndEditor"

MAJOR =  1
MINOR =  0
PATCH = 13
BUILD =  0

VERNUM = (MAJOR*10000)+(MINOR*1000)+(PATCH*100)+(BUILD)

MANIFEST = f"""\
<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
<assembly xmlns="urn:schemas-microsoft-com:asm.v1" manifestVersion="1.0">
  <assemblyIdentity type="win32" name="{AUTHOR}.{PROJECT}.{APPNAME}" version="{MAJOR}.{MINOR}.{PATCH}.{BUILD}"/>
</assembly>
"""

manifest_file = open(MANIFEST_FILE, "w")
manifest_file.write(MANIFEST)
manifest_file.close()

SOURCE = f"""\
/*******************************************************************************
 * Application version information in multiple numeric and string forms.
 * Authored by Joshua Robertson
 * Available Under MIT License (See EOF)
 *
*******************************************************************************/

#ifndef VERSION_HPP__ /*//////////////////////////////////////////////////////*/
#define VERSION_HPP__

#ifdef COMPILER_HAS_PRAGMA_ONCE
#pragma once
#endif

/*////////////////////////////////////////////////////////////////////////////*/

/* -------------------------------------------------------------------------- */

GLOBAL constexpr int APP_VER_MAJOR = {MAJOR};
GLOBAL constexpr int APP_VER_MINOR = {MINOR};
GLOBAL constexpr int APP_VER_PATCH = {PATCH};
GLOBAL constexpr int APP_VER_BUILD = {BUILD};

GLOBAL constexpr const char* APP_VER_STR = "{MAJOR}.{MINOR}.{PATCH}.{BUILD}";
GLOBAL constexpr int         APP_VER_NUM =  {VERNUM};

/* -------------------------------------------------------------------------- */

/*////////////////////////////////////////////////////////////////////////////*/

#endif /* VERSION_HPP__ //////////////////////////////////////////////////////*/

/*******************************************************************************
 *
 * Copyright (c) 2020 Joshua Robertson
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *
*******************************************************************************/
"""

source_file = open(VERSION_FILE, "w")
source_file.write(SOURCE)
source_file.close()
