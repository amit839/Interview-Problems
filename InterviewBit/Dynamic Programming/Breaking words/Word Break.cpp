// https://www.interviewbit.com/problems/word-break/

bool go(int index, int siz, string& A, set<string>& st, vector<int>& dp){
    if(index == siz) return 1;
    
    int &ans = dp[index];
    if(ans != -1) return ans;
    ans = 0;
    string t;
    for(int i = index; i < siz; i++){
        t += A[i];
        if(st.find(t) != st.end()) ans |= go(i + 1, siz, A, st, dp);
    }
    return ans;
}


int Solution::wordBreak(string A, vector<string> &B) {
    set<string> st(B.begin(), B.end());
    int n = A.size();
    vector<int> dp(n, -1);
    
    return go(0, n, A, st, dp);
}
