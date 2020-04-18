// https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/

class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        int n = 50;
        vector<long long> fibo(n);
        fibo[0] = fibo[1] = 1;
        for(int i = 2; i < n; i++) fibo[i] = fibo[i - 1] + fibo[i - 2];
        
        int ans = 0;
        long long times = k;
        
        for(int i = n - 2; i > -1; i--){
            if(fibo[i] <= times){
                times -= fibo[i];
                ans++;
            }
            if(times < 1) break;
        }
        
        return ans;
    }
};