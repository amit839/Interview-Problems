/*
Given an array of integers A of size N. Value of a subarray is defined as BITWISE OR of all elements in it.
Return the sum of Value of all subarrays of A % 10^9 + 7. 

Input Format:   The first argument given is the integer array A.
Output Format:  Return the sum of Value of all subarrays of A % 10^9 + 7.

Constraints
1 <= N <= 10^5
1 <= A[i] <= 10^8

For Example
Input 1:
    A = [1, 2, 3, 4, 5]
Output 1:
    71
Explaination 1:
    Value( [ 1 ] ) =    1
    Value( [ 1,2 ] ) =    3
    Value( [ 1,2,3 ] ) =    3
    Value( [ 1,2,3,4 ] ) =    7
    Value( [ 1,2,3,4,5 ] ) =    7
    Value( [ 2 ] ) =    2
    Value( [ 2,3 ] ) =    3
    Value( [ 2,3,4 ] ) =    7
    Value( [ 2,3,4,5 ] ) =    7
    Value( [ 3 ] ) =    3
    Value( [ 3,4 ] ) =    7
    Value( [ 3,4,5 ] ) =    7
    Value( [ 4 ] ) =    4
    Value( [ 4,5 ] ) =    5
    Value( [ 5 ] ) =    5
    Sum of all these values = 71

Input 2:
    A = [7, 8, 9, 10]
Output 2:
    110
*/

const int mod = 1e9 + 7;
typedef long long ll;

int getSubarray(int bit, vector<int>& arr, int n){
    ll sum = 0, ct = 0;
    for(int i = 0; i < n; i++){
        if(!(arr[i] & (1 << bit))) ct++;
        else{
            sum += (ct * (ct + 1)) / 2;
            ct = 0;
            sum %= mod;
        }
    }
    sum += (ct * (ct + 1)) / 2;
    return sum % mod;
}

int Solution::solve(vector<int> &A) {
    ll n = A.size(), ans = 0;
    for(int i = 0; i < 31; i++){
        ll tsum = getSubarray(i, A, n);
        ans += ((1 << i) * ((n * (n + 1)) / 2 - tsum));
        ans %= mod;
    }
    return ans;
}
