class Solution {
public:
    
    double power(double a, long long b){
        if(b < 1) return 1;
        
        double ans = power(a, b / 2);
        ans *= ans;
        if(b & 1) ans *= a;
        
        return ans;
    }
    
    double myPow(double x, int b) {
        bool sign = 0;
        long long n = b;
        
        if(n < 0) sign = 1;
        n = abs(n);
        
        double ans = power(x, n);
        
        if(sign) ans = 1.0 / ans;
        
        return ans;
    }
};