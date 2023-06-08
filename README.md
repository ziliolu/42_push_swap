# Push Swap

![Push Swap](https://your-image-url.com)

## Table of Contents

- [Introduction](#introduction)
- [Algorithm](#algorithm)
- [Installation](#installation)
- [Usage](#usage)
- [🚨 Disclaimer](#🚨disclaimer)

## Introduction

This project is part of the curriculum at 42 school and aims to sort a stack of integers using a limited set of operations. The goal is to develop an efficient sorting algorithm that can arrange the stack in ascending order using the fewest number of moves possible.

This README file will guide you through the project, explaining the algorithm used, how to install and run the program, and how to contribute to its development.

## Algorithm

The algorithm used in this project is based on the article ["Push Swap: Solving Sorting Problem with Minimized Number of Operations"](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) by Ayodele Yogundairo.

The algorithm can be summarized as follows:

1. **Chunk Division**: The algorithm starts by dividing the stack into two parts: stack A (initially containing all the numbers) and an empty stack B. It selects a chunk size based on the total number of elements in stack A.

2. **Push to Stack B**: The algorithm identifies the "cheapest" number in stack A, which is the number that requires the fewest number of moves to be pushed to stack B. It uses various operations (swap, rotate, reverse rotate) to move this number to stack B.

3. **Sorting in Stack B**: Once a number is pushed to stack B, the algorithm evaluates the remaining numbers in stack A and performs a similar process to find the next "cheapest" number. It continues this process until all numbers are in stack B.

4. **Back to Stack A**: After all the numbers are in stack B, the algorithm begins the process of moving the numbers back to stack A while keeping them in the correct order. It performs a series of operations to achieve this.

The algorithm optimizes the number of moves by carefully selecting the "cheapest" number at each step and utilizing the available operations to minimize the total number of moves required.

## Installation

To install and run Push Swap, follow these steps:

1. Clone the repository:
   ```bash
   git clone https://github.com/ziliolu/push_swap.git
2. Navigate to the project directory:
   ```bash
   cd push_swa
3. Compile the program by running the following command:
   ```bash
   make 
   
## Usage 
To use Push Swap, follow these steps:

1. Execute the program with a list of integers as arguments. For example:
   ```bash
   ./push_swap 42 17 9 33 1
2. The program will output a series of instructions representing the operations required to sort the stack. For example:
   ```bash
   sa
   pb
   rra
   ...
## 🚨 Disclaimer

Maybe you could notice a different coding style.
At 42 we need to follow some rules according to the coding standard of the school such as:

```bash
- No for, do while, switch, case or goto 
- No functions with more than 25 lines 
- No more than 5 functions per each file
- No more than 5 variables in the same function
- No assigns and declarations assigns in the same line
```
[Click here](https://github.com/MagicHatJo/-42-Norm/blob/master/norme.en.pdf) to read the norm file of 42 school. 


