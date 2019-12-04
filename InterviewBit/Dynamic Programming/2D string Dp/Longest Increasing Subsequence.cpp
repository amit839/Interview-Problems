// https://www.interviewbit.com/problems/longest-increasing-subsequence/

int Solution::lis(const vector<int> &A) {
    int n = A.size();
    vector<int> lis(n);
    for(int i = 0; i < n; i++){
        int ct = 1;
        for(int j = i - 1; j > -1; j--){
            if(A[j] < A[i]) ct = max(ct, lis[j] + 1); 
        }
        lis[i] = ct;
    }
    return *max_element(lis.begin(), lis.end());
}
