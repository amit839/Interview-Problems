// https://www.interviewbit.com/problems/jump-game-array/

int Solution::canJump(vector<int> &A) {
    int n = A.size();
    int reach = A[0];
    for(int i = 1; i < n; i++){
        reach--;
        reach = max(reach, A[i]);
        if(reach <= 0) return 0;
    }
    return 1;
}
