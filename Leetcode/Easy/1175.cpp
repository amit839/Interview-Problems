// link to the problem statement : https://leetcode.com/contest/weekly-contest-152/problems/prime-arrangements/

const int mod = 1e9 + 7;

class Solution {
public:
    bool isPrime(int n){
        for(int i = 2; i <= sqrt(n); i++){
            if(n % i == 0) return false;
        }
        return true;
    }
    long long fact(long long n){
        if(n == 0) return 1;
        return (1LL * n * fact(n - 1)) % mod;
    }
    int numPrimeArrangements(int n) {
        int ct = 0;
        for(int i = 2; i <= n; i++) if(isPrime(i)) ct++;
        return (1LL * fact(ct) * fact(n - ct)) % mod;
    }
};