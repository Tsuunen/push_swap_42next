*This project has been created as part of the 42 curriculum by nahecre and relaforg*

# Description
The **push_swap** project introduces ourselves to algorithm complexity. The main goal is to sort a stack. To do so, we have two stack and some primitive actions. We are asked to write various algorithm based on their big-O complexity. We also have to implement an adaptive strategy that choose the right algorithm to choose based on the result of an heuristic-like function that returns a numeric representation of the disorder in a stack. We were proposed to make a checker as a bonus, the checker will tell if the solution provided on the stantard input is correct and actually sort the stack given as a program parameter.

# insctructions
## push_swap program
### Compilation
```bash
make
```
### Usage
```bash
./push_swap <num1> <num2> ... # the first num will be at the top of the a stack
```

## checker program
### Compilation
```bash
make bonus
```
### Usage
```bash
./checker <num1> <num2> ... # the first num will be at the top of the a stack
```
You can now pipe or write your solution to the standard input

# Ressources
 - Various Geeks for Geeks article to understand the different algorithms
 - ChatGPT to explain the left over questions on the algorithms
 - ChatGPT to try debugging code without much success if none

# Algorithms

## Simple Algorithm
We chose the **selection sort** because it is an easy and quick algorithm to understand and implement

## Medium Algorithm
We opted for a **bucket style sorting** method, it gives a great challenge in order to track various position in a stack even after rotations and pushes.

## Complex Algorithm
For the last one we implemented a **binary LSB radix sort**. The radix is a non-comparison sorting algorithm. So it makes it a really intresting algorithm to try understand and implement.
