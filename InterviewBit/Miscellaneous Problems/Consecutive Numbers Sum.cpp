/*
Given a positive integer A. Return the number of ways it can be written as a sum of consecutive positive integers. 

Input Format:   The first and the only argument of input contains an integer, A.
Output Format:  Return an integer, representing the answer as described in the problem statement.

Constraints:
1 <= A <= 1e9
Examples:
Input 1:
    A = 5

Output 1:
    2

Explanation 1:
    The 2 ways are:
    => [5]
    => [2, 3]

Input 2:
    A = 15

Output 2:
    4

Explanation 2:
    The 4 ways are:
    => [15]
    => [7, 8]
    => [4, 5, 6]
    => [1, 2, 3, 4, 5]

*/

int Solution::solve(int A) {
    int ans = 0;
    
    while(!(A & 1)) A >>= 1;
    
    int bound = sqrt(A);

    for(int i = 1; i <= bound; i += 2){
        if(A % i == 0){
            if(i == A/i) ans++;
            else ans += 2;
        }
    }
    return ans;
}
