/*
Given a non-negative integer A represented as a string, remove B digits from the number so that the new number is the smallest possible. Note:
The length of A is less than 10002 and will be >= B.
The given num does not contain any leading zero.

Input Format:
The first argument of input contains a string A, of length N.
The second argument of input contains the integer B.

Output Format:
Return a string representing the minimum possible number after removing B digits.
Constraints:
1 <= N <= 10002
0 <= S[i] <= 9

Examples:

Input 1:
    A = "1432219"
    B = 3
Output 1:
    "1219"
Explanation 1:
    You can remove 4, 3 and one of the 2s.

Input 2:
    A = "10200"
    B = 1
Output 2:
    "200"
Explanation 2:
    You can remove 1.

Input 3:
    A = "10"
    B = 2
Output 3:
    "0"
Explanation 3:
    You can remove all the digits.
*/

string Solution::solve(string A, int B) {
    int n = A.size();
    if(n == B) return "0";
    
    stack<char> st;
    for(int i = 0; i < n; i++){
        while(!st.empty() and st.top() > A[i] and B > 0){
            B--;
            st.pop();
        }
        st.push(A[i]);
    }
    while(B--){
        st.pop();
    }
    string output;
    while(!st.empty()){
        output += st.top();
        st.pop();
    }
    reverse(output.begin(), output.end());
    int i = 0;
    while(i < output.size() and output[i] == '0') i++;
    
    output = output.substr(i);
    if(output.size() == 0) return "0";
    
    return output;
}
