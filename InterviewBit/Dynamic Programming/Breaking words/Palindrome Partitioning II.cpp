// https://www.interviewbit.com/problems/palindrome-partitioning-ii/

int go(int index, int siz, vector<int>& dp, vector<vector<int>>& palin){
    if(index == siz) return -1;
    
    int &cuts = dp[index];
    if(cuts != -1) return cuts;
    
    cuts = siz - index - 1;
    for(int j = index; j < siz; j++){
        if(palin[index][j]){
            cuts = min(cuts, 1 + go(j + 1, siz, dp, palin));
        }
    }
    return cuts;
}

int Solution::minCut(string a) {
    int n = a.size();
    vector<vector<int>> palin(n, vector<int>(n));
    
    for(int i = 0; i < n; i++){
        int l = i, r = i;
        palin[i][i] = 1;
        
        while(l - 1> -1 and r + 1< n and a[l - 1] == a[r + 1]){
            l--;r++;
            palin[l][r] = 1;
        }
        l = i, r = i + 1;
        if(r < n and a[l] == a[r]) palin[l][r] = 1;
        else continue;
        while(l - 1 > -1 and r + 1 < n and a[l - 1] == a[r + 1]){
            l--;r++;
            palin[l][r] = 1;
        }
    }
    
    vector<int> dp(n, -1);
    
    return go(0, n, dp, palin);
}
