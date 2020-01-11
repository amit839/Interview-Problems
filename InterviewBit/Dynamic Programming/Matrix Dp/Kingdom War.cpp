// https://www.interviewbit.com/problems/kingdom-war/


int Solution::solve(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size();
    
    for(int j = m - 2; j > -1; j--){
        for(int i = 0; i < n; i++){
            A[i][j] += A[i][j + 1];
        }
    }
    for(int i = n - 2; i > -1; i--){
        for(int j = 0; j < m; j++){
            A[i][j] += A[i + 1][j];
        }
    }
    int ans = INT_MIN;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ans = max(ans, A[i][j]);
        }
    }
    return ans;
}
