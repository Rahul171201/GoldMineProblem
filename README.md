# GoldMineProblem
A simple dp problem based on optimization

# Question
Given a gold mine of n∗ m dimensions. Each field in this mine contains a positive integer which is the amount of gold in tons. Initially the miner is at first column but can be at any row. He can move only (right,right up,right down) that is from a given cell, the miner can move to the cell diagonally up towards the right or right or diagonally down
towards the right. Find out maximum amount of gold he can collect.

# Abstract
In simple words, the problem can be explained as follows:
The miner starts at the first column, (any row). And after every step he moves one step right into the next column (either towards right or diagonally right), until he reaches
the final column. Our job is to make the miner move through the path which gives him the maximum gold and return the maximum amount of gold collected.
We will solve the given problem using dynamic programming approach

# Algorithmic Design
The Algorithm we designed is based on top down approach of dynamic programming to find the most suitable path that provides maximum sum of elements of matrix.
The recursive approach calculates the maximum amount of gold that can be obtained from every path in the matrix and stores it in a dp table to reduce time in calculating
overlapping sub problems.

# Approach
* dp table of dimension n∗ m is first created and initialized with a value of -1 for all cells.
* The recursive function gets input in the form of mine matrix and its dimensions(n,m), dp matrix, current row(i) and current column(j).
* The function calculates the maximum amount of gold that can be obtained if miner starts from the current position(i,j) and stores it in dp table.
* In every move we find the maximum of right, right_up, and right_down and then add it with that mine[i][j] and also store and return the result in dp[i][j].
* If we have reached outside the dimensions of mine matrix then we return 0. Therefore, when we are in the first row we cannot move right_up, when we are in last row we
cannot move right_down and when we reach last column the recursive function ends.
* If we reach any cell from where the maximum amount of gold has already been calculated ie. dp[i][j] is not equal to -1 then we return the value in dp[i][j].
* We run the following function for every cell in the first column. At last, we find the maximum of all rows and first column and return it as our answer.

# Algorithmic Analysis
* Time Complexity :
    The Algorithm uses recursion with memorization to produce a dynamic programming solution. The algorithm on worst case traverses through the whole
matrix of n∗ m dimension, hence the worst case time complexity of this algorithm is O(n∗ m)

* Space Complexity :
  The space complexity of the program is O(n∗ m) as we store the intermediate results in a dp table which has dimensions of n∗ m
  

