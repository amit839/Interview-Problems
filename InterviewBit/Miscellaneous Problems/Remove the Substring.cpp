/*
Given 2 strings of lowercase alphabets A and B of size N and M respectively. it is guaranteed that B is a subsequence of A.
For example, the strings "test", "tst", "tt", "et" and "" are subsequences of the string "test". But the strings "tset", "se", "contest" are not subsequences of the string "test".
You need to remove some substring(contiguous subsequence) from A of maximum possible length such that after removing this substring B will remain a subsequence of A. If you want to remove the substring A[l::r] then the string A will be transformed to A1A2…Al−1Ar+1Ar+2…A|A|−1A|A| (where |A| is the length of A). Find and return the maximum possible length of the substring you can remove so that B is still a subsequence of A. 

Input Format
The first argument given is the string A.
The second argument given is the string B.

Output Format
Return the maximum possible length of the substring you can remove so that B is still a subsequence of A.

Constraints
1 <= N, M <= 10^5
For Example

Input 1:
    A = "bbaba"
    B = "bb"
Output 1:
    3
Explaination 1:
    A[2::4] = "aba" can be removed and B still remains the subsequence of A[0::1]


Input 2:
    A = "bbaba"
    B = "ab"
Output 2:
    2

*/


int Solution::solve(string A, string B) {
    map<char,set<int>> mp;
    int n = A.size(), m = B.size();
    
    for(int i = 0; i < n; i++){
        mp[A[i]].insert(i);
    }
    
    int ans = 0;
    
    int i = 0, j = 0, prev_index = -1;
    
    vector<pair<char,int>> pos;
    
    while(j < m){
        if(A[i] == B[j]){
            pos.push_back({A[i], i});
            
            ans = max(ans, i - prev_index - 1);
            prev_index = i;
            
            i++;
            j++;
        }
        else i++;
    }
    ans = max(ans, n - prev_index - 1);
    
    
    int k = pos.size(), right_bound = n;
    
    for(int i = k - 1; i >= 0; i--){
        char ch = pos[i].first;
        int id = pos[i].second;
        
        if(mp[ch].size() > 1){
            auto it = mp[ch].lower_bound(right_bound);
            it--;
            
            if(i > 0){
                ans = max(ans, *it - pos[i - 1].second - 1);
            }
            right_bound = *it;
        }
        else right_bound = id;
        
    }
    ans = max(ans, right_bound);
    
    return ans;
}
