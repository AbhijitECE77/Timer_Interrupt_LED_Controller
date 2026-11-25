# Week 2 - LED Toggle Firmware Simulation

**Author:** Abhijit Karpurshetti  
**Language:** C  
**Project type:** Software simulation

## Overview

This small C program demonstrates LED state toggling. A software counter advances whenever `TimerInterruptHandler()` is called. After 500 calls, the program toggles its simulated LED state and prints `LED ON` or `LED OFF`.

## Important implementation note

In this version, `TimerInterruptHandler()` is called directly from the `while` loop. The loop and its short delay simulate repeated timer ticks; they are **not a hardware timer interrupt**. The program changes a software variable and prints a message; it does not drive an STM32 GPIO pin. The delay is not calibrated to milliseconds.

This version is suitable as a basic software simulation. For an STM32 hardware demonstration, configure a hardware timer in STM32CubeIDE and toggle the board's LED GPIO from the timer-period callback.

## Build and run

Install GCC, then open a terminal in this folder.

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic -O2 main.c -o led_controller
./led_controller
```

On Windows using the MSYS2 UCRT64 terminal:

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic -O2 main.c -o led_controller.exe
./led_controller.exe
```

The program runs continuously. Stop it with **Ctrl+C**. It should print alternating lines similar to:

```text
LED ON
LED OFF
LED ON
LED OFF
```

## Source file

- `main.c` - standalone simulation code with inline comments.

## Manual verification record

After compiling and running on your computer, record the compiler version and confirm that the output alternates between `LED ON` and `LED OFF`. No physical-board or hardware-interrupt test is claimed for this software-simulation version.

## Push to GitHub

Create an empty repository on GitHub, then run the following from this folder, replacing the URL with your repository URL:

```bash
git remote add origin https://github.com/<your-username>/<your-repository>.git
git push -u origin main
```
