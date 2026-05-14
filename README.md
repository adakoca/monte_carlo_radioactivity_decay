
# Monte Carlo Simulation: Radioactive Decay

An independent physics computation project designed to simulate the stochastic nature of radioactive isotope decay using pseudo-random number generation (PRNG) techniques in C++17.

## Features
- **Stochastic Modeling:** Utilizes `std::mt19937` (Mersenne Twister) to simulate individual atomic decay probabilities.
- **Dynamic Visuals:** Custom ASCII/Unicode progress bars rendering remaining atom percentages directly in the Linux terminal.
- **Memory Efficient:** Pure standard library execution with zero heavy dependencies, aligned with competitive high-energy physics frameworks.

## Technical Stack
- **Language:** C++17
- **Environment:** Linux / Bash Terminal
- **Compilation:** `g++ -std=c++17 -O2 radioactive_decay.cpp -o decay`

## Purpose
This project serves as a foundational exercise in computational nuclear physics, demonstrating how statistical algorithms mimic physical quantum behaviors (such as half-life decay constants) prior to official coursework at ČVUT.
