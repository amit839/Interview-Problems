/*
A sequence of integers is called nice if its elements are arranged in blocks like in [3, 3, 3, 4, 1, 1]. Formally, if two elements are equal, everything in between must also be equal. Let's define difficulty of a sequence as a minimum possible number of elements to change to get a nice sequence. However, if you change at least one element of value x to value y, you must also change all other elements of value x into y as well. For example, for [3, 3, 1, 3, 2, 1, 2] it isn't allowed to change first 1 to 3 and second 1 to 2. You need to leave 1's untouched or change them to the same value. Print difficulty of given sequence A of size N. 

Input Format:
    First and only argument of input is a single integer array A

Output Format:
    return a single integer denoting difficulty of A.

Constraints:
    1 <= N <= 200000
    1 <= A[i] <= 200000

For Example:

Input 1:
    A = [3, 7, 3, 7, 3]
Output 1:
    2
Explanation:
    change both 7 to 3

Input 2:
    A = [3, 3, 7, 7, 7, 1]
Output 2:
    0

Input 3:
    A = [3, 3, 1, 3, 2, 1, 2]
Output 3:
    4

*/

int Solution::solve(vector<int> &A) {
    unordered_map<int,int> freq;
    unordered_map<int, pair<int,int>> pos;
    
    int n = A.size();
    for(int i = 0; i < n; i++){
        freq[A[i]]++;
        if(pos.find(A[i]) == pos.end()){
            pos[A[i]] = {i, i};
        }
        else{
            pos[A[i]].second = i;
        }
    }
    int same = 0, mval = 0;
    unordered_set<int> st;
    for(int i = 0; i < n; i++){
        st.insert(A[i]);
        mval = max(mval , freq[A[i]]);
        
        if(pos[A[i]].second == i){
            st.erase(A[i]);
        }
        if(st.size() == 0){
            same += mval;
            mval = 0;
        }
    }
    return n - same;
}
