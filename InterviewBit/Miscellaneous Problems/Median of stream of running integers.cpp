/*
Given an array of integers A denoting a stream of integers. A new array of integer B is formed and C are formed. Each time an integer is encountered in a stream append it at the end of B and append median of array B at the C. Find and return the array C. NOTE: 1.If the number of elements are n in B and n is odd then consider medain as B[n/2] ( B must be in sorted order). 2.If the number of elements are n in B and n is even then consider medain as B[n/2-1] ( B must be in sorted order). 

Input Format
The only argument given is the integer array A.

Output Format
Return the array C.

Constraints
1 <= length of the array <= 100000
1 <= A[i] <= 1000000000

For Example
Input 1:
    A = [1, 2, 3, 4, 5]
Output 1:
    C = [1, 1, 2, 2, 3]

    stream          median
    [1]             1
    [1, 2]          1
    [1, 2, 3]       2
    [1, 2, 3, 4]    2
    [1, 2, 3, 4, 5] 3

Input 2:
    A = [5, 17, 100, 11]
Output 2:
    C = [5, 5, 17, 11]

*/

vector<int> Solution::solve(vector<int> &A) {
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    
    int n = A.size();
    vector<int> output(n);
    for(int i = 0; i < n; i++){
        if(left.size() == 0 and right.size() == 0){
            right.push(A[i]);
        }
        else if(left.size() > 0 and A[i] > left.top()){
            right.push(A[i]);
        }
        else left.push(A[i]);
        
        if(left.size() < right.size()){
            left.push(right.top());
            right.pop();
        }
        else if(left.size() > right.size() + 1){
            right.push(left.top());
            left.pop();
        }
        output[i] = left.top();
    }
    return output;
}
