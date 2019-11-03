/*
Given an N x M matrix of positive integers representing the height of each unit cell in a 2D elevation map. Return the volume of water it is able to trap after raining. 

Input Format
The first and the only argument given is the integer matrix A.

Output Format
Return the volume of water that is trapped after raining.

Constraints
1 <= N, M <= 110
1 <= A[i] <= 19999

For Example
Input 1:
    A = [   [1, 4, 3, 1, 3, 2]
            [3, 2, 1, 3, 2, 4]
            [2, 3, 3, 2, 3, 1]   ]
Output 1:
    4

*/

typedef pair<int,int> pi;

int dr[] = {0, -1, 0, 1};
int dc[] = {-1, 0, 1, 0};

int Solution::solve(vector<vector<int> > &A) {
    priority_queue<pi, vector<pi>, greater<pi>> q;
    const int n = A.size(), m = A[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if( i != 0 and j != 0 and i != n - 1 and j != m - 1) continue;
            visited[i][j] = true;
            q.push({A[i][j], i * m + j});
        }
    }
    int ans = 0, mval = -1;

    while(!q.empty()){
        pi temp = q.top();
        q.pop();
        int i = temp.second / m, j = temp.second % m;
        mval = max(mval, temp.first);

        for(int k = 0; k < 4; k++){
            int x = i + dr[k], y = j + dc[k];
            if(x < 0 or x > n - 1 or y < 0 or y > m - 1 or visited[x][y]) continue;

            visited[x][y] = true;
            if(A[x][y] < mval){
                ans += mval - A[x][y];
            }
            q.push({A[x][y], x * m + y});
        }
    }
    return ans;
}
