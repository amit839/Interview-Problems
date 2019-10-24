/*
Given an array of citations A (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index. According to the definition of h-index: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each." Note: If there are several possible values for h, the maximum one is taken as the h-index. 

Input Format:   
First and only argument of input contains an integer array A of size N

Output Format:
    return a single integer denoting h-index.

Constraints:
    1 <= N <=3e6
    1 <= A[i] <= 1e9

For Example:
Input 1:
    A = [3, 0, 6, 1, 5]
Output 1:
    3

Explanation 1:
    [3,0,6,1,5] means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively. 
    Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, her h-index is 3.
Input 2:
    A = [20, 10, 5]
Output 2:
    3

*/

int Solution::solve(vector<int> &A) {
    int n = A.size();
    sort(A.begin(), A.end());
    int h = 0;
    for (int i = n - 1; i >= 0; i--) {
        int R = n - i;
        if (i == 0) {
            if (A[i] >= R) h = max(h, R);
        }
        else if (A[i] >= R && A[i - 1] <= R) h = max(h, R);
    }
    return h;
}
