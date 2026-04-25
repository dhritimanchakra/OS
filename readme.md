# RISC-V Kernel

A minimal RISC-V kernel built in C, following the "Operating System in 1000 Lines" guide.

## Features
- Boots on QEMU (riscv32)
- SBI console output
- Trap handling with register saving
- Physical memory layout via linker script

## Requirements
- clang with RISC-V target
- qemu-system-riscv32
- lld linker

## Running
```bash
./run.sh
```

## Status
Work in progress.