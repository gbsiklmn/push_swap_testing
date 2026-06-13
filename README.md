*This project has been created as part of the 42 curriculum by <lstarkov>, <jduque-n>*

# Description

Push_swap is a sorting program that uses two stacks and a limited set of operations to sort integers.
The program receives a list of integers as arguments and prints a sequence of operations that sorts the numbers in ascending order.
The goal of the project is to implement efficient sorting strategies while minimizing the number of operations.

Only the following stack operations are allowed:
sa (swap a): Swap the first two elements at the top of stack a. Do nothing if there is only one or no elements.
sb (swap b): Swap the first two elements at the top of stack b. Do nothing if there is only one or no elements.
ss : sa and sb at the same time.
pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
ra (rotate a): Shift up all elements of stack a by one. The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by one. The first element becomes the last one.
rr : ra and rb at the same time.
rra (reverse rotate a): Shift down all elements of stack a by one. The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by one. The last element becomes the first one.
rrr : rra and rrb at the same time.

## Allowed Functions:
read
write
malloc
free
exit
ft_printf or any equivalent we coded

## Project Structure:

push_swap.h

main.c
parsing.c

utils.c
output_utils.c
ft_split.c

stack.c
swap.c
push.c
rotate.c
reverse_rotate.c

disorder.c
sort_adaptive.c
sort_simple.c
sort_medium.c
sort_complex.c

Makefile
Readme.md

Before sorting begins, the program measures how far the stack is from being sorted using a disorder metric.
This metric is calculated once before sorting and is used to select the most appropriate algorithm.

The program uses an adaptive sorting strategy that selects a different algorithm depending on the measured disorder.
### disorder < 0.2 
	Simple sort O(n²)
### 0.2 ≤ disorder < 0.5 
	Chunk-based sort O(n√n)
### disorder ≥ 0.5
	Radix sort O(n log n)
This approach allows the program to adapt to different input distributions and reduce the number of operations.

### Specialized routines are used for very small inputs:
	sort_3
These functions use minimal operations and avoid unnecessary overhead.

### Simple Sort (O(n²))
assign normalized indices
move elements in increasing order
push misplaced elements to stack B
restore them to stack A
This approach is efficient for nearly sorted data.

### Chunk Sort (O(n√n))
Used for medium disorder.
The stack is divided into chunks of consecutive indices.
Process:
Push elements belonging to the current chunk from A → B
Continue until all chunks are processed
Rebuild the stack by pushing the largest elements back to A
This method significantly reduces the number of rotations compared to naive approaches.

### Radix Sort (O(n log n))
Used for highly disordered input.
Steps:
	Normalize numbers to indices
	Process bits from least significant to most significant
	For each bit:
		push elements with bit 0 to stack B
		rotate elements with bit 1
	Move everything back to stack A
Radix sort guarantees predictable performance for large inputs.

# Instructions

## Build
compile the project: make
clean object files: make clean 
remove everything: make fclean 
recompile: make re

## Usage:

Example:
$>./push_swap 4 2 3 1

Output:
pb
ra
sa
pa

Each line represents one operation performed on the stacks.

## An optional strategy selector:
--simple Forces the use of your O(n^2 ) algorithm.
--medium Forces the use of your O(n sqrt(n)) algorithm.
--complex Forces the use of your O(n log n) algorithm.
--adaptive Forces the use of your adaptive algorithm based on disorder (the default behavior if no selector is given).

$>./push_swap --simple 5 4 3 2 1
rra
pb
rra
pb
sa
rra
pa
pa

$>ARG="4 7 53 3 4242 21"; ./push_swap --adaptive $ARG
ra
ra
ra
pb
ra
ra
pb
pb
rra
pa
pa
pa

Operation count:
$>ARG="4 7 53 3 4242 21"; ./push_swap --adaptive $ARG | wc -l
12

###
The optional benchmark mode (--bench) must display, after sorting:
	The computed disorder (% with two decimals).
	The name of the strategy used and its theoretical complexity class.
	The total number of operations.
	The count of each operation type (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr).

$>Test shuf -i 0-9999 -n 500 > args.txt ; ./push_swap --bench $(cat args.txt) 2>bench.txt | ./checker_linux $(cat args.txt)
OK
$>cat bench.txt 
disorder: 51.43%
strategy: Complex / O(n log n)
total_ops: 6784
sa: 0	sb: 0	ss: 0	pa: 2284	pb: 2284
ra: 2216	rb: 0	rr: 0	rra: 0	rrb: 0	rrr: 0

### Errors:
$>./push_swap --adaptive 1 2 2 5  
Error
$>./push_swap --adaptive o 1 2 3    
Error

## Test
ARG=$(seq -500 500 | shuf | head -n 100 | tr '\n' ' ')
./push_swap $ARG | ./checker_linux $ARG

# Resources

C Standard Library documentation;
42 curriculum subject and PDF resources;
google.com, stackoverflow.com, reddit.com and other online resources were used in the creation of the project;
AI was used to clarify some technical issues;
Google Translate and Grammarly were used in preparing the documentation file;


# Summary
This implementation combines multiple sorting strategies into an adaptive framework.
By measuring the initial disorder of the input stack, the program dynamically selects the most appropriate algorithm to minimize the number of operations.

## Contributions
We (<lstarkov> and <jduque-n>) worked together on this code, writing each function as the normal workflow required it to complete each part of the complete project, attempted to improve its efficiency in some algorithms, and tested it for efficiency, memory leaks and error management. We also consulted with other students that had already completed the projecton on the internal logic ofthe program, how to demonstrate if we understood the code and the specifics of the evaluation process.

