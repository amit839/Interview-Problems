// https://www.interviewbit.com/problems/min-jumps-array/

int Solution::jump(vector<int> &A) {
    int n = A.size();
    if(n < 2) return 0;
    int jumps = 0, curEnd = 0, reach = 0;
    for (int i = 0; i < n - 1; i++) {
        reach = max(reach, i + A[i]);
        if (i == curEnd) {
            jumps++;
            curEnd = reach;
        }
        if(reach)
    }
    return jumps;
}
