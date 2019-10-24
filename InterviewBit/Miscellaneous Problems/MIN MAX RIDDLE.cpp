/*
Given an array of integers A of size N. Find and return an array containing the maximum of the minimum(s) of every window size in the array. The window size varies from 1 to N. For example, given A = [6, 3, 5, 1, 12], consider window sizes of 1 through 5. Windows of size 1 are [6], [3], [5], [1], [12]. The maximum of the minimum(s) values of these windows is 12. Windows of size 2 are [6, 3], [3, 5], [5, 1], [1, 12] and their minima are {3, 3, 1, 1}. The maximum of these values is 3. Continue this process through window size 5 to finally consider the entire array. All of the answers are [12, 3, 3, 1, 1]. 

Input Format:
The first and only argument given is the integer array A.

Output Format:
Return an array containing the maximum of the minimum(s) of every window size in the array. The window size varies from 1 to N.

Constraints
1 <= N <= 1000000
1 <= A[i] <= 100000

For Example

Input 1:
    A = [3, 5, 4, 7, 6, 2]
Output 1:
    [7, 6, 4, 4, 3, 2]

Input 2:
    A = [2, 6, 1, 12]
Output 2:
    [12, 2, 1, 1]

*/

vector<int> Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<int> left(n), right(n);
    stack<int> st;
    
    for(int i = 0; i < n; i++){
        while(!st.empty() and A[st.top()] >= A[i]) st.pop();
        if(st.empty()){
            left[i] = -1;
            st.push(i);
        }
        else{
            left[i] = st.top();
            st.push(i);
        }
    }
    while(!st.empty()) st.pop();
    
    for(int i = n - 1; i >= 0; i--){
        while(!st.empty() and A[st.top()] >= A[i]) st.pop();
        if(st.empty()){
            right[i] = n;
            st.push(i);
        }
        else{
            right[i] = st.top();
            st.push(i);
        }
    }
    
    vector<int> ans(n);
    for(int i = 0; i < n; i++){
        int k = right[i] - left[i] - 1;
        ans[k - 1] = max(ans[k - 1], A[i]);
    }
    for(int i = n - 2; i >= 0; i--){
        ans[i] = max(ans[i], ans[i + 1]);
    }
    return ans;
}
