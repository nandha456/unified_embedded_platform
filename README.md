# UnixTron

> A CLI-first embedded development platform for building and flashing microcontroller firmware.

UnixTron is a lightweight command-line development tool designed to simplify the embedded firmware workflow.

Instead of manually running the compiler, linker, binary conversion tools, and flashing utilities, UnixTron provides a unified CLI that coordinates the complete process.

## Current Target

**MCU:** STM32F401CC  
**Architecture:** ARM Cortex-M4  
**Toolchain:** `arm-none-eabi-gcc`  
**Programming interface:** USB DFU  
**Flashing tool:** `dfu-util`  
**Build system:** CMake  
**Implementation:** C++

---

# What UnixTron Does

UnixTron currently provides:

- Project generation
- Project configuration
- ARM GCC compilation
- Startup code generation
- Linker script generation
- ELF generation
- Binary generation
- STM32 USB DFU flashing
- Unified `run` workflow

The basic workflow is:

```text
Source Code
     │
     ▼
  UnixTron
     │
     ├── Compile
     │
     ├── Link
     │
     ├── Generate BIN
     │
     └── Flash
            │
            ▼
       STM32F401CC
```

#Architecture

UnixTron is designed around separation of responsibilities.
```text
                    UnixTron CLI
                         |
                         v
                 Command Registry
                         |
             +-----------+-----------+
             |                       |
        BuildCommand            FlashCommand
             |                       |
             v                       v
          Builder                 Flasher
             |                       |
             +-----------+-----------+
                         |
                         v
                   Process Layer
                         |
             +-----------+-----------+
             |                       |
             v                       v
      arm-none-eabi-gcc          dfu-util
             |                       |
             v                       v
       firmware.bin  --------->   STM32
```

# Installation

## Requirements

On Arch Linux:

```bash
sudo pacman -S cmake gcc arm-none-eabi-gcc arm-none-eabi-binutils dfu-util
```

Verify the ARM compiler:

```bash
arm-none-eabi-gcc --version
```

Verify DFU:

```bash
dfu-util --version
```

---

# Build UnixTron

Clone the repository:

```bash
git clone <YOUR_REPOSITORY_URL>
```

Enter the project directory:

```bash
cd unixtron
```

Configure the project:

```bash
cmake -S . -B build
```

Build UnixTron:

```bash
cmake --build build
```

The executable will be generated at:

```text
build/unixtron
```

Run UnixTron:

```bash
./build/unixtron
```
