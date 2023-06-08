# Push Swap

![Push Swap](https://your-image-url.com)

## Table of Contents

- [Introduction](#introduction)
- [Algorithm](#algorithm)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Introduction

Welcome to Push Swap! This project is part of the curriculum at 42 school and aims to sort a stack of integers using a limited set of operations. The goal is to develop an efficient sorting algorithm that can arrange the stack in ascending order using the fewest number of moves possible.

This README file will guide you through the project, explaining the algorithm used, how to install and run the program, and how to contribute to its development.

## Algorithm

The algorithm used in this project is inspired by the article ["Push Swap: Solving Sorting Problem with Minimized Number of Operations"](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) by Ayodele Yogundairo.

The algorithm can be divided into two main phases:

1. **Divide and Conquer**: In this phase, the algorithm divides the stack into chunks of sorted numbers. It starts by finding the maximum and minimum values in the stack. Then, it iteratively divides the stack into two parts: the numbers already sorted in stack B and the remaining unsorted numbers in stack A. This process continues until all the numbers are sorted in stack B.

2. **Merge**: Once the stack is divided into sorted chunks, the algorithm merges these chunks together into a single sorted stack. It achieves this by analyzing the position of the numbers in stack B and performing specific operations to rearrange them in the correct order.

The algorithm carefully selects the operations to minimize the number of moves required, using techniques such as finding the optimal rotation and the best position to insert a number into stack B.

## Installation

To install and run Push Swap, follow these steps:

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/push_swap.git
