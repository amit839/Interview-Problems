/*
The Ruler of HackerLand believes that every citizen of the country should have access to a library. Unfortunately, HackerLand was hit by a tornado that destroyed all of its libraries and obstructed its roads! As you are the greatest programmer of HackerLand, the ruler wants your help to repair the roads and build some new libraries efficiently. HackerLand has A cities numbered from 1 to A. The cities are connected by bidirectional roads. A citizen has access to a library if:
Their city contains a library.
They can travel by road from their city to a city containing a library.
If Cost to build road is C and Cost to build library is D, find minimum cost of making libraries accessible to all the citizens. 

Input Format:
    First argument of Input contains a single integer A denoting number of nodes.
    Second argument of Input contains M x 2 integer matrix B. Each row correspond to a road and both integer denote end points of road. 
    Third argument of Input contains single integer C denoting cost of building road.
    Fourth argument of Input contains single integer D denoting cost of building library.

Output Format:
    Return a single integer denoting minimum cost of making libraries accessible to all.

Constraints:
    1 <= A <= 100000
    0 <= M <= min(A*(A-1)/2 , 100000)
    1 <= B[1],B[2] <= A
    1 <= C,D <= 20000

For Example:
Input 1:
    A = 3, B = [[1, 2], [3, 1], [2, 3]], C = 1, D = 2
Output 1:
    4
Explanation 1:
    one solution is to build library at city 1 and rebuild road 1-2 and 2-3. Cost of this is 2 + 1 + 1 = 4.

Input 2:
    A = 6, B = [[1, 2], [2, 4], [1, 3], [3, 4]], C = 5, D = 2
Output 2:
    12
Explanation 2:
    Build 1 library ar each city.

*/

void dfs(int id, vector<vector<int>>& graph, vector<bool>& visited, int& ct){
    if(visited[id]) return;
    
    visited[id] = 1;
    ct++;
    for(auto x: graph[id]){
        if(x == id) continue;
        dfs(x, graph, visited, ct);
    }
}

int Solution::solve(int A, vector<vector<int> > &B, int C, int D) {
    if(C >= D) return A * D;
    
    vector<vector<int>> graph(A + 1);
    for(auto edge : B){
        int x = edge[0], y = edge[1];
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vector<bool> visited(A + 1);
    
    int ans = 0, comp = 0;
    
    for(int i = 1; i <= A; i++){
        if(!visited[i]){
            int ct = 0;
            dfs(i, graph, visited, ct);
            ans += (ct - 1) * C;
            comp++;
        }
    }
    
    return ans + comp * D;
}
