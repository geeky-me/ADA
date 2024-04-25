INTRODUCTION

Calculating the run time of various algorithms for larger inputs.

SELECTION SORT

The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array. The subarray which is already sorted. Remaining subarray which is unsorted. In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray.

![image](https://github.com/geeky-me/ADA/assets/158138672/c3fe902d-75d5-4a71-92fd-7910a031c6a1)

TIME COMPLEXITY = O(n^2)

TOWERS OF HANOI

Tower of Hanoi is a mathematical puzzle where we have three rods (A, B, and C) and N disks. Initially, all the disks are stacked in decreasing value of diameter i.e., the smallest disk is placed on the top and they are on rod A. The objective of the puzzle is to move the entire stack to another rod (here considered C), obeying the following simple rules: Only one disk can be moved at a time. Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack i.e. a disk can only be moved if it is the uppermost disk on a stack. No disk may be placed on top of a smaller disk.

![image](https://github.com/geeky-me/ADA/assets/158138672/fb3b8af2-6253-4eb1-8367-ad69455c8b4e)

TIME COMPLEXITY = O(2^n)

SUM OF AN ARRAY

We are to add the elements of the array recursively and after the base case is reached,we have to return the first element and return until all recursive calls end.

![image](https://github.com/geeky-me/ADA/assets/158138672/2cb6780e-cd43-47ea-9cc5-dbc987bb6a58)

TIME COMPLEXITY = O(n)

Horner Rule

Horner’s rule is an algorithm for evaluating a polynomial of the form cn​x^n+c(n−1)​x^(n−1)+⋯+c1​x+c0​at a given value of x , where cn​,cn−1​,…,c0​are coefficients. The algorithm is based on the observation that the polynomial can be rewritten as ((⋯((cn​x+cn−1​)x+cn−2​)x+⋯)x+c1​)x+c0​, which reduces the number of multiplications and additions needed to compute the values.


![image](https://github.com/geeky-me/ADA/assets/158138672/86645d0d-00fe-49db-9aa3-258d3eea55db)

TIME COMPLEXITY = O(n)

Truth table for n numbers
It computes all possible boolean values of the number.

TIME COMPLEXITY = O(2^n)

PERMUTATION GENERATOR

It computes all possible ways in which a string of letters can be arranged.It does the swapping of all the characters recursively ,keeping one of them fixed and printing after the string length is reached.

![image](https://github.com/geeky-me/ADA/assets/158138672/5aa22957-899a-461c-9635-1437495baa43)

TIME COMPLEXITY = O(2^n)

LINEAR SEARCH

![image](https://github.com/geeky-me/ADA/assets/158138672/88e40bcd-813a-49eb-a5e6-101138bcc611)

In this algorithm,we search whether the element is present in the array or not.We do so by comparing each of the element of the array with the key element.If the element is present we return the index of the element, else if the element is not present we return -1.

TIME COMPLEXITY = O(n)

BINARY SEARCH

Binary Search is a search algorithm that is faster than the linear search algorithm. Binary Search is used to search the position of the target element in a sorted array by repeatedly dividing the search space in half. Binary search eliminates half portion of the array with each comparison.

Best Case Complexity:

![image](https://github.com/geeky-me/ADA/assets/158138672/b3e10404-9c38-4a5e-b72b-b2c543103fa3)

TIME COMPLEXITY = O(logn)

POWER OF A NUMBER

In this algorithm we multiply the number with the recursive call and decrease the power by 1 and when power becomes zero,we return 1.

![image](https://github.com/geeky-me/ADA/assets/158138672/f013da88-5f5d-4938-806c-8a132e2c83c3)

TIME COMPLEXITY = O(n)

MAGIC SQUARE

A magic square of order n is an arrangement of n2 numbers, usually distinct integers, in a square, such that the n numbers in all rows, all columns, and both diagonals sum to the same constant. A magic square contains the integers from 1 to n2. The constant sum in every row, column and diagonal are called the magic constant or magic sum, M.

TIME COMPLEXITY = O(n^2)

MERGING OF TWO SORTED LISTS

![image](https://github.com/geeky-me/ADA/assets/158138672/10de7cb4-f8b0-4548-8f3d-495eca754854)

Create an array arr3[] of size n1 + n2. Simultaneously traverse arr1[] and arr2[]. Pick smaller of current elements in arr1[] and arr2[], copy this smaller element to next position in arr3[] and move ahead in arr3[] and the array whose element is picked. If there are remaining elements in arr1[] or arr2[], copy them also in arr3[].

TIME COMPLEXITY = O(n)

CORRECT POSITION OF PIVOT

The target of partitions is to place the pivot (any element can be chosen to be a pivot) at its correct position in the sorted array and put all smaller elements to the left of the pivot, and all greater elements to the right of the pivot.

TIME COMPLEXITY = O(n)

MERGE SORT

Merge sort is a recursive algorithm that continuously splits the array in half until it cannot be further divided i.e., the array has only one element left (an array with one element is always sorted). Then the sorted subarrays are merged into one sorted array.

TIME COMPLEXITY = O(n*logn)

QUICK SORT

The key process in quickSort is a partition(). The target of partitions is to place the pivot (any element can be chosen to be a pivot) at its correct position in the sorted array and put all smaller elements to the left of the pivot, and all greater elements to the right of the pivot. Partition is done recursively on each side of the pivot after the pivot is placed in its correct position and this finally sorts the array.

![image](https://github.com/geeky-me/ADA/assets/158138672/95b432e0-cbb8-4401-804d-94b977a3d499)

TIME COMPLEXITY(average case) = O(nlogn)

TIME COMPLEXITY(worst case) = O(n^2)

QUICK SORT(ITERATIVE)

The process includes doing partition and putting the larger list in the stack and sorting the smaller list.This algorithm saves a lot of space.

TIME COMPLEXITY = O(n*logn)

MAXIMUM AND MINIMUM (DIVIDE AND CONQUER)

In this, the array is divided into two halves. Then using recursive approach maximum and minimum numbers in each halves are found. Later, return the maximum of two maxima of each half and the minimum of two minima of each half.

TIME COMPLEXITY = O(n)

Kth SMALLEST

In this, we focus on calculating the kth smallest element from the list with the help of partition algorithm.

TIME COMPLEXITY(WORST CASE) = O(n^2)

KNAPSACK

Given the weights and profits of N items, in the form of {profit, weight} put these items in a knapsack of capacity W to get the maximum total profit in the knapsack.

There are three methods through which the profit can be maximized :-

non-increasing profit

non-increasing profit/weight ratio

non-decreasing weight

![image](https://github.com/geeky-me/ADA/assets/158138672/3d525a96-79f6-411a-bdd5-782f603d611e)


TIME COMPLEXITY = O(n*logn)

ACTIVITY SELECTION

In this, we are given with the starting and the ending time of the meetings,we are supposed to select the meetings in such a way so that maximum meetings can be held in a room.

![image](https://github.com/geeky-me/ADA/assets/158138672/79ffe4e5-cd46-4d8d-a5dc-1693ca9c1e52)

TIME COMPLEXITY = O(n*logn)

DIJKSTRA

The algorithm maintains a set of visited vertices and a set of unvisited vertices. It starts at the source vertex and iteratively selects the unvisited vertex with the smallest tentative distance from the source. It then visits the neighbors of this vertex and updates their tentative distances if a shorter path is found. This process continues until the destination vertex is reached, or all reachable vertices have been visited.

TIME COMPLEXITY = O(V^2)

PRIMS

The algorithm starts with an empty spanning tree. The idea is to maintain two sets of vertices. The first set contains the vertices already included in the MST, and the other set contains the vertices not yet included. At every step, it considers all the edges that connect the two sets and picks the minimum weight edge from these edges. After picking the edge, it moves the other endpoint of the edge to the set containing MST.

TIME COMPLEXITY = O(V^2)

MULTISTAGE GRAPH(fcost)

The program calculates the cost of the shortest path from each node to the end node using dynamic programming. It iterates backward starting from the last node (end node) and calculates the cost of the shortest path from each node to the end node.

TIME COMPLEXITY = O(V^2)

ASSEMBLY LINE

This algorithm computes the minimum time required to complete the assembly process and determines the optimal path (line) for each station. It utilizes dynamic programming to compute the minimum time recursively.

TIME COMLEXITY = O(n)

LONGEST COMMON SUBSEQUENCE

The program implements the Longest Common Subsequence (LCS) problem using dynamic programming. It calculates the length of the LCS between two given strings and prints the LCS along with arrows indicating the matching characters.

TIME COMPLEXITY = O(m*n). m and n are the lengths of the input strings.

MATRIX CHAIN MULTIPLICATION

The program utilizes dynamic programming to solve the Matrix Chain Multiplication problem, aiming to minimize the number of scalar multiplications needed to multiply a sequence of matrices. It iteratively computes the optimal number of multiplications for various subproblems, storing the results to avoid redundant computations.

TIME COMLEXITY = O(n^3)

N QUEENS PROBLEM

The code employs a backtracking algorithm to solve the N-Queens problem efficiently. At its core, it iteratively places queens on a chessboard, ensuring no two queens threaten each other. The place function checks for conflicts with existing queens, validating potential queen placements. Through recursive backtracking in the Nqueens function, the algorithm systematically explores all possible configurations, marking valid solutions when all queens are placed successfully.

Solution for 4 Queens:

![image](https://github.com/geeky-me/ADA/assets/158138672/542462d6-9c59-4379-92bf-038db44cc7a1)


TIME COMPLEXITY = O(n!)

SUM OF SUBSETS

The provided algorithm tackles the sum-of-subsets problem using a backtracking approach. It recursively explores different combinations of elements in the array to identify subsets that sum up to a target value. At each step, the algorithm considers whether including the current element in the subset would lead to a valid solution, and if so, it adds the element to the subset and continues exploring further. If adding the element would exceed the target sum, the algorithm backtracks, excluding the element and exploring other possibilities. This process continues until all possible combinations are explored or until a valid subset summing up to the target value is found. By systematically pruning the search space using backtracking, the algorithm efficiently identifies all subsets that meet the sum condition, providing an optimized solution for the sum-of-subsets problem.

TIME COMPLEXITY = O(2^n)

M-COLORING PROBLEM

The provided algorithm aims to solve the m-coloring problem using backtracking. It attempts to color the vertices of a given graph using at most m colors, ensuring that no adjacent vertices share the same color. The main function initializes the graph's adjacency matrix, sets the number of vertices and colors, and calls the mcoloring function with initial parameters. The mcoloring function recursively explores different color assignments for each vertex, backtracking when necessary. If a valid coloring is found, it prints the coloring and returns. If the graph cannot be colored with the given number of colors, it outputs a message indicating so. The nextvalue function determines the next color to try for a vertex, ensuring that it doesn't violate the m-coloring constraint. Through systematic exploration and backtracking, the algorithm efficiently identifies whether the graph can be colored with at most m colors and, if so, provides one of the possible colorings. TIME COMPLEXITY = O(n*m^n)

MATRIX MULTIPLICATION(DIVIDE AND CONQUER)

The code employs Strassen's algorithm for matrix multiplication, a divide-and-conquer approach. It recursively partitions the input matrices A and B into smaller submatrices until reaching base cases. It then performs multiplications and additions according to Strassen's algorithm. The resulting matrix C is printed. This method optimizes multiplication for large matrices by reducing the number of scalar multiplications.

TIME COMPLEXITY = O(n^3)
