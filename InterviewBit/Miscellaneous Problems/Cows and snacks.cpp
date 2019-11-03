/*
The legendary Farmer John is throwing a huge party, and animals from all over the world are hanging out at his house. His guests are hungry, so he instructs his cow Bessie to bring out the snacks! Moo! There are A snacks flavors, numbered with integers 1,2,…,A. Bessie has A snacks, one snack of each flavor. Every guest has exactly two favorite flavors. The procedure for eating snacks will go as follows:
First, Bessie will line up the guests in some way.
Then in this order, guests will approach the snacks one by one.
Each guest in their turn will eat all remaining snacks of their favorite flavor. In case no favorite flavors are present when a guest goes up, they become very sad.
Help Bessie to minimize the number of sad guests by lining the guests in an optimal way. 

Input Format:
    First argument of input contains a single integer A
    Second argument of input contains a 2 x M integer matrix B denoting favorite flavor of each guest.

Output Format:
    return a single integer denoting the smallest possible number of sad guests.

Constraints:
    2 <= N <= 100000
    1 <= M <= 100000
    1 <= B[i][0] , B[i][1] <= N
    B[i][0] != B[i][1]

For Example:

Input 1:
    A = 5 , B = [[1, 2], [4, 3], [1, 4], [3, 4]]
Output 1:
    1
Explanation:
    Bessie can order the guests like this: 3,1,2,4. Guest 3 goes first and eats snacks 1 and 4. Then the guest 1 goes and eats the snack 2 only, because the snack 1 has already been eaten. Similarly, the guest 2 goes up and eats the snack 3 only. All the snacks are gone, so the guest 4 will be sad.

Input 2:
    A = 6 , B =[[2, 3], [2, 1], [3, 4], [6, 5], [4, 5]]
Output 2:
    0

*/

void dfs(int node, int parent,  vector<vector<int>> &graph, vector<bool> &visited, int &ct){
    if(visited[node]) return;
    
    visited[node] = 1;
    ct++;
    
    for(auto x: graph[node]){
        if(x == parent) continue;
        dfs(x, node, graph, visited, ct);
    }
}

int Solution::solve(int A, vector<vector<int> > &B) {
    int n = B.size();
    vector<vector<int>> graph(A + 1);
    for(int i = 0; i < n; i++){
        graph[B[i][0]].push_back(B[i][1]);
        graph[B[i][1]].push_back(B[i][0]);
    }
    
    vector<bool> visited(A + 1);
    for(int i = 1; i <= A; i++){
        if(!visited[i]){
            int ct = 0;
            dfs(i, -1, graph, visited, ct);
            n -= (ct - 1);
        }
    }
    return n;
}
