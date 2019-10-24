/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down). Write a function to count the total strobogrammatic numbers that exist in the range of A <= num <= B. 

Note: Since A and B are very big they are given in input as strings 

Input Format:
    First argument contains a string A.
    Second argument contains a string B.

Output Format:
Return a single integer denoting the count.

Constraints:
1 <= A <= B <= 10^15

For Example:

Input 1:
    A = 50, B = 100
Output 1:
    3
Explanation:
    69, 88 and 96 are 3 strobogrammatic numbers.

Input 2:
    A = 1, B = 10
Output 2:
    2
*/

#include<bits/stdc++.h>
using namespace std;

vector<char> input = {'0','1','6','8','9'};
map<char,char> mp;

bool compare_upper(string a, string b){
    if(a.size() == b.size()) return a <= b;
    return a.size() < b.size();
}
bool compare_lower(string a, string b){
    if(a.size() == b.size()) return a >= b;
    return a.size() > b.size();
}

void countNumber(int index, int n, string& A, string& B, string temp, int& ans){
    if((n & 1 and index > n / 2) or (!(n & 1) and index >= n / 2)){
        if(compare_upper(temp, B) and compare_lower(temp, A)) {
            ans++;
        }
        return;
    }
    for(int i = 0; i < 5; i++){
        if(index == 0 and i == 0) continue;
        if(n & 1 and index == n / 2 and (i == 2 or i == 4)) continue;
        temp[index] = input[i];
        temp[n - index - 1] = mp[input[i]];
        countNumber(index + 1, n, A, B, temp, ans);
    }
}

int solve(string A, string B) {
    int n = B.size();
    mp['0'] = '0';
    mp['1'] = '1';
    mp['6'] = '9';
    mp['8'] = '8';
    mp['9'] = '6';
    
    int ans = 0;
    for(int i = 1; i <= n; i++){
        countNumber(0, i, A, B, string(i, '*'), ans);
    }
    return ans;
}
