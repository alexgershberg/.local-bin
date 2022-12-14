#!/usr/bin/env python3

import os
import sys
import subprocess

if len(sys.argv) <= 1:
    print("usage: c [file.c / file.cpp]")
    exit(1)


name, ext = os.path.splitext(sys.argv[1])

if ext not in [".c", ".cpp"]:
    print("Error. Invalid file extension.")
    print("Allowed file extensions: .c .cpp")
    exit(1)


# Compile
compile = subprocess.run(["clang++", "-std=c++20", f"{name + ext}", "-o", name])
if compile.returncode != 0:
    exit(1)


# Run
run = subprocess.run([f"./{name}"])
if run.returncode != 0:
    exit(1)

# Delete
delete = subprocess.run(["rm", name])
if delete.returncode != 0:
    exit(1)