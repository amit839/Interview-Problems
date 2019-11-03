
/*
There are N plants in a garden. Each of these plants has been treated with some amount of pesticide. After each day, if any plant has more pesticide than the plant on its left, being weaker than the left one, it dies. You are given the initial values of the pesticide in each of the plants. Print the number of days after which no plant dies, i.e. the time after which there are no plants with more pesticide content than the plant to their left. 

Input Format:
The first and the only argument of input contains an integer array A, representing the pesticide levels in the i-th plant.

Output Format:
Return an integer representing the number of days after which no plants die.

Constraints:
1 <= N <= 1e5
1 <= A[i] <= 1e9

Examples:
Input 1:
    A = [6, 5, 8, 4, 7, 10, 9]

Output 1:
    2

Explanation 1:
    Initially, all the plants are alive.

    1st plant has 6 units of pesticide.
    2nd plant has 5 units of pesticide.
    3rd plant has 8 units of pesticide and so on.

    After day 1, plants 3, 5 and 6 die.

    Now, the plants are:
        [6, 5, 4, 9]

    After day 2, 4th plant dies.

    Now the plants are [6, 5, 4].

    No plants die after day 2. Thus, you can return 2.

*/

int Solution::solve(vector<int> &a) {
    
    stack<pair<int, int>> st;
    int ans = 0, n = a.size();

    for(int i = n - 1; i > -1; i--){
        int temp = 0;
        while(!st.empty() and a[i] < st.top().first){
            temp++;
            temp = max(temp, st.top().second);
            st.pop();
        }
        ans = max(ans, temp);
        st.push({a[i], temp});
    }
    return ans;
}
