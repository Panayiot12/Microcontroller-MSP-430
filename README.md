# MSP430 Timer_A HAL Driver

[cite_start]This repository contains the source code for **Part 1** of the final project for the "Embedded Systems Design" course (Democritus University of Thrace, 2025-2026)[cite: 7, 8].

## Project Overview
[cite_start]The goal of this project is to develop a **Hardware Abstraction Layer (HAL)** for the Timer_A module of the MSP430 microcontroller[cite: 29]. [cite_start]This driver allows users to configure and control the timer without needing to directly manipulate hardware registers (such as `TACTL`, `TAR`, `TACCTLx`)[cite: 18, 38].

## Features
The HAL library implements the following functionalities through a high-level C API:
* [cite_start]**Configuration:** Struct-based setup for Clock Source (ACLK, SMCLK), Input Divider, and Counting Mode (Up, Continuous, etc.)[cite: 32, 34].
* [cite_start]**Control:** Functions to Start and Stop the timer execution[cite: 35].
* [cite_start]**Counter Management:** Read and Reset the current timer value (`TAR`)[cite: 36].
* [cite_start]**PWM Generation:** Dedicated function to easily configure Pulse Width Modulation signals by setting Period and Duty Cycle[cite: 37].

## File Structure
* [cite_start]`timerA_HAL_23.h`: Header file containing the configuration structs, enums, and function prototypes[cite: 43].
* [cite_start]`timerA_HAL_23.c`: Source file with the implementation of the driver and register manipulation logic[cite: 43].
* [cite_start]`timerA_main_23.c`: Demonstration application showing usage examples (Timer counting & PWM output)[cite: 45].

*(Note: 'xx' corresponds to the team number)*

## Development Environment
* [cite_start]**Microcontroller:** TI MSP430 (Family x1xx)[cite: 14, 30].
* [cite_start]**IDE:** IAR Embedded Workbench[cite: 9].
