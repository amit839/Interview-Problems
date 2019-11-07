// https://leetcode.com/problems/prime-palindrome/

bool found;
int ans;
int N;

class Solution {
public:
    
    bool isPrime(long long n){
        if(n < 2) return false;
        for(long long i = 2; i * i <= n; i++){
            if(n % i == 0) return false;
        }
        return true;
    }
    
    void generate(int i, int j, string s){
        if(found) return;
        
        if(i > j){
            long long val = stoll(s);
            if(!isPrime(val)) return;
            if(val >= N){
                ans = val;
                found = true;
            }
            return;
        }
        
        for(char k = '0'; k <= '9'; k++){
            if(k == '0' and i == 0) continue;
            s[i] = s[j] = k;
            generate(i + 1, j - 1, s);
        }
    }
    
    int primePalindrome(int val) {
        found = false;
        N = val;
        int n = to_string(N).size();
        
        for(int i = n; i <= 9; i++){
            generate(0, i - 1, string(i, '*'));
            if(found) return ans;
        }
        
        return -1;
   