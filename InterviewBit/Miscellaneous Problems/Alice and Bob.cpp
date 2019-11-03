/*
It is so boring in the summer holiday, isn't it? So Alice and Bob have invented a new game to play. The rules are as follows. First, they get a set of A distinct integers. And then they take turns to make the following moves. During each move, either Alice or Bob (the player whose turn is the current) can choose two distinct integers X and Y from the set, such that the set doesn't contain their absolute difference |X - Y|. Then this player adds integer |X - Y| to the set (so, the size of the set increases by one). If the current player has no valid move, he (or she) loses the game. The question is who will finally win the game if both players play optimally. Remember that Alice always moves first. 

Input Format:
    First and only agrument of input is an integer array A containing distinct numbers.

Output Format:
    Return a single integer 1 for Alice and 0 for Bob.

Constraints:
    1 <= N <= 100
    1 <= A[i] <= 10^9

For Example:
Input 1:
    A = [2, 3]
Output 1:
    1
Explanation 1:
    Alice add 1 to the set A. Bob can't make anymore moves.

Input 2:
    A = [5, 3]
Output 2:
    1

Input 3:
    A = [5, 6,7]
Output 3:
    0

*/

int Solution::solve(vector<int> &A) {
    int n = A.size();
    int gcd = A[0];
    int mvalue = *max_element(A.begin(), A.end());
    
    for(int i = 1; i < n; i++){
        gcd = __gcd(gcd, A[i]);
    }
    int total_numbers = mvalue / gcd;
    return (total_numbers - n) & 1;
}
