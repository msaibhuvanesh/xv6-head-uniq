

## 🧠 Project Summary

This project implements two custom Unix-like commands for the xv6 operating system: `head` and `uniq`. These were developed in **user space**, tested on **xv6-public**, and compiled using `make qemu-nox`.



---

## 🔧 System Setup & Compilation

### Environment
- **WSL (Ubuntu 20.04)** on Windows
- **xv6-public** repository

### Setup & Execution

```bash
`# Step 1: Enter Ubuntu via WSL
cd xv6-public

# Step 2: Clean previous builds
make clean     # (screenshot included)

# Step 3: Compile xv6 with new user programs
make qemu-nox  # (screenshot included)`

## 🛠️ Makefile Update

To ensure your `head` and `uniq` programs are compiled with xv6, update the `UPROGS` section of the `Makefile` as shown below:

```makefile
UPROGS=\
  _head\
  _uniq\
  ...

FILE STRUCTURE

xv6-public/
├── head.c                  # Custom head command
├── uniq.c                  # Custom uniq command
├── Makefile                # Modified to include new programs
├── screenshots/
│   ├── head/               # Output examples for all head cases
│   ├── uniq/               # Output examples for all uniq flags
├── Project1-README.md      # This file



🧩 Command 1: head

📄 Description
head.c replicates the UNIX head command by reading the first n lines from a file or standard input.

🧪 Supported Modes

Mode	Description
head	Reads 14 lines from stdin
head file.txt	Reads 14 lines from a file
head -n N file.txt	Reads N lines from the file
head -n N file1 file2	Reads N lines from both files separately
head file1 file2	Reads 14 lines from both files
🔧 Key Functions
emptyString() – Clears buffer
zerocase() – Handles no-argument input
firstcase() – Reads from a single file
secondcase() – Handles -n with one file
thirdcase() – Handles two files, with or without -n

🧩 Command 2: uniq

📄 Description
uniq.c filters adjacent duplicate lines from files or standard input and supports several common UNIX-style flags for line comparison and filtering.

🧪 Supported Flags

Flag	Description
(none)	Print unique lines only
-c	Print unique lines with occurrence counts
-d	Print only duplicate lines
-i	Ignore case while comparing lines
`cat file	uniq`
🔧 Key Functions
emptyString() – Clears buffer
pipeFlag() – Input from stdin
noFlag() – Processes file input
countFlag() – Supports -c
duplicateFlag() – Supports -d
ignoreFlag() – Supports -i
toLowerCase() – Used for case-insensitive comparison


