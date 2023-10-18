[project-logo](/assets/project_logo.png)

# OpenOS - A Simple Operating System

This repository contains the source code for a simple operating system, designed as an educational project to understand the fundamentals of OS development.

## Directory Structure

```
.
├── src
│   ├── descriptors.c
│   ├── descriptors.h
│   ├── gdt.asm
│   ├── kernel.c
│   ├── screen.c
│   ├── screen.h
│   └── boot.asm
├── iso
│   ├── kernel
│   │   └── kernel.bin
│   └── boot
│       └── grub
│           └── stage2_eltorito
└── make.sh
```

## Prerequisites

- A cross-compiler toolchain compatible with the target architecture (x86_64).
- `mkisofs` for generating ISO images.
- QEMU for running the OS.

## Building and Running

1. Ensure you have all the prerequisites installed.
2. Execute the `make.sh` script from the root directory:
```bash
$ chmod +x make.sh
$ ./make.sh
```
This will compile the source files, generate an ISO image, and run the OS in QEMU.

## Contact

For any queries, issues, or suggestions, please open an issue on GitHub.

---

**Note:** This is a basic operating system and should be used for educational purposes only.
