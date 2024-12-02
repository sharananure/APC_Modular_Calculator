# Arbitrary Precision Calculator (APC)

## Description

The **Arbitrary Precision Calculator (APC)** can handle large integer arithmetic using doubly linked lists, surpassing the limitations of standard data types like `int` or `long`. This calculator supports addition, subtraction, multiplication, and division of large integers, including negative values.

## Features

- Addition, Subtraction, Multiplication, and Division of large integers.
- Supports both positive and negative numbers.
- Utilizes **doubly linked lists** for precise handling of large integers.

## How to Compile and Run

### 1. **Compilation**

To compile the program, open your terminal and navigate to the directory containing the source files. Use the following command:

gcc Main.c Addition.c Subtraction.c Multiplication.c Division.c linked_list_operations.c -o APC

### 2. **Running the Program**
Run the compiled program using:
./a.out

### 3. **Input Format**
The program can be run interactively or using command-line arguments in the format:
USAGE: <operand1> <operator> <operand2>

## Example
./a.out 10 + 5

## Files Overview
File Name                  Description
-------------------------  ----------------------------------------------------
Main.c                     Main driver of the program.
main.h                     Header file containing function declarations.
Addition.c                 Logic for addition of large numbers.
Subtraction.c              Logic for subtraction of large numbers.
Multiplication.c           Logic for multiplication of large numbers.
Division.c                 Logic for division of large numbers.
linked_list_operations.c   Utility functions for linked list operations.

## Features
1. Addition
2. Subtraction
3. Multiplication
4. Division
5. Supports large integers using doubly linked lists
6. Handles positive and negative numbers

## License
This project is licensed under the MIT License.


