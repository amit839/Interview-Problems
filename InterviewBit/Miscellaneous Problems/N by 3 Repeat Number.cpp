/*
You're given a read only array of n integers. Find out if any integer occurs more than n/3 times in the array in linear time and constant additional space. If so, return the integer. If not, return -1. If there are multiple solutions, return any one. Example :
Input : [1 2 3 1 1]
Output : 1 
1 occurs 3 times which is more than 5/3 times. 

*/

int Solution::repeatedNumber(const vector<int> &A) {
    
    int num1 = INT32_MIN, num2 = INT32_MIN, freq1 = 0, freq2 = 0, n = A.size();
    
    for(auto x: A){
        if(x == num1) freq1++;
        else if(x == num2) freq2++;
        else if(freq1 == 0){
            num1 = x;
            freq1 = 1;
        }
        else if(freq2 == 0){
            num2 = x;
            freq2 = 1;
        }
        else{
            freq1--, freq2--;
        }
    }
    int a, b;
    a = b = 0;
    for(auto x : A){
        if(x == num1) a++;
        else if(x == num2) b++;
    }
    if(a > n / 3) return num1;
    else if(b > n / 3) return num2;
    else return -1;
}