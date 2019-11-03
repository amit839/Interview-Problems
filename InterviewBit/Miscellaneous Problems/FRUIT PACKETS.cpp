/*
Given A apples, B bananas and C cherries. A balanced fruit packet must have:-
Atleast 1 apple
Atleast 1 banana
Exactly 3 fruits
Find and return the maximum number of balanced fruit packets which can be formed using A apples, B bananas and C cherries. 

Input Format:
The first argument given is the integer A.
The second argument given is the integer B.
The third argument given is the integer C.

Output Format:
Return the maximum number of balanced fruit packets which can be formed using A apples, B bananas and C cherries.

Constraints:    0 <= A, B, C <= 10^8

For Example
Input 1:
    A = 3
    B = 6
    C = 0
Output 1:
    3
Explaination 1:
    All three balanced fruit packets consist of 1 apple and 2 bananas

Input 2:
    A = 10
    B = 1
    C = 10
Output 2:
    1

*/
int Solution::solve(int a, int b, int c) {
    return min(min(a, b), (a + b + c) / 3);
}
