
# Push Swap

<p align="center">
  <img src="https://img.shields.io/github/languages/top/ziliolu/42_push_swap?color=#FFFFFF&style=flat-square" />
  <img src="https://img.shields.io/badge/score-100%20%2F%20100-success?color=#FFFFFF&style=flat-square" />
  <img src="https://img.shields.io/badge/status-finished-success?color=#FFFFFF&style=flat-square" />
  <img src="https://img.shields.io/github/last-commit/ziliolu/42_push_swap?color=#FFFFFF&style=flat-square" />
</p>

## Table of Contents

- [About](#about)
- [Algorithm](#algorithm)
- [Operations](#operations)
- [Installation](#installation)
- [Usage](#usage)
- [Testers](#testers)
- [Disclaimer](#disclaimer)

## About

This project is part of the curriculum at 42 school and aims to sort a stack of integers using a limited set of operations. The goal is to develop an efficient sorting algorithm that can arrange the stack in ascending order using the fewest number of moves possible.

This README file will guide you through the project, explaining the algorithm used, how to install and run the program, and how to contribute to its development.

[Click here](https://github.com/ziliolu/42_push_swap/blob/main/push_swap.pdf) to access the complete subject of this project.

## Algorithm

The algorithm used in this project is based on the article ["Push Swap — A journey to find most efficient sorting algorithm"](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) by [Ali Yigit Ogun](https://github.com/byaliego).

It can be summarized as follows:

1. **Chunk Division**: The algorithm starts by dividing the stack into two parts: stack A (initially containing all the numbers) and an empty stack B.

2. **Push to Stack B**: The algorithm identifies the "cheapest" number in stack A, which is the number that requires the fewest number of moves to be pushed to stack B. It uses different operations (rotate, reverse rotate) to move this number to stack B.

3. **Sorting in Stack B**: Once a number is pushed to stack B, the algorithm evaluates the remaining numbers in stack A and performs a similar process to find the next "cheapest" number. It continues this process until all numbers are in stack B.

4. **Back to Stack A**: After all the numbers are in stack B, the algorithm begins the process of moving the numbers back to stack A while keeping them in the correct order, always caring about the cheapest numbers in both stacks. It performs a series of operations to achieve this.

## Operations

The Push Swap program utilizes a limited set of operations to manipulate the stacks and sort the numbers. Here are the available operations:

- `sa` Swap the top two elements of stack A.
- `sb` Swap the top two elements of stack B.
- `pa` Push the top element from stack B to stack A.
- `pb` Push the top element from stack A to stack B.
- `ra` Rotate all elements of stack A upwards. The top element becomes the bottom element.
- `rb` Rotate all elements of stack B upwards. The top element becomes the bottom element.
- `rr` Perform **ra** and **rb** simultaneously.
- `rra` Rotate all elements of stack A downwards. The bottom element becomes the top element.
- `rrb` Rotate all elements of stack B downwards. The bottom element becomes the top element.
- `rrr` Perform **rra** and **rrb** simultaneously.

These operations allow the algorithm to manipulate the numbers in the stacks and perform various sorting strategies. The algorithm analyzes the state of the stacks and chooses the most appropriate operations to minimize the number of moves required for sorting.

You can find the implementation of these operations in the source code of the Push Swap project.

## Installation

To install and run Push Swap, follow these steps:

1. Clone the repository:
   ```bash
   git clone git@github.com:ziliolu/42_push_swap.git
2. Navigate to the project directory:
   ```bash
   cd 42_push_swap
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
   pb
   pb
   rra
   rra
   ...
## Testers 

1. [Push Swap Visualizer](https://github.com/o-reo/push_swap_visualizer) provides a graphical representation of the sorting process performed by the push_swap program. It helps to visualize and understand the sorting algorithm in action.

## Disclaimer

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


