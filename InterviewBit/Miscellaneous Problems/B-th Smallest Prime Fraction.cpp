/*
A sorted array of integers, A contains 1, plus some number of primes. Then, for every p < q in the list, we consider the fraction p/q. What is the B-th smallest fraction considered? Return your answer as an array of integers, where answer[0] = p and answer[1] = q. 

Input Format:
The first argument of input contains the integer array, A.
The second argument of input contains an integer B.

Output Format:
Return an array of two integers, where answer[0] = p and answer[1] = q.

Constraints:
1 <= length(A) <= 2000
1 <= A[i] <= 30000
1 <= K <= length(A)*(length(A) - 1)/2

Examples:
Input 1:
    A = [1, 2, 3, 5]
    B = 3

Output 1:
    [2, 5]

Explanation 1:
    The fractions to be considered in sorted order are:
        [1/5, 1/3, 2/5, 1/2, 3/5, 2/3]
    The third fraction is 2/5.

Input 2:
    A = [1, 7]
    B = 1

Output 2:
    [1, 7]

Explanation 2:
    The fractions to be considered in sorted order are:
        [1/7]
    The first fraction is 1/7.
*/

bool comp(pair<int,int> a, pair<int,int> b){
    return a.first * b.second < a.second * b.first;
}

vector<int> Solution::solve(vector<int> &A, int B) {
    vector<pair<int,int>> input;
    int n = A.size();
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            input.push_back({A[i], A[j]});
        }
    }
    sort(input.begin(), input.end(), comp);
    
    return {input[B - 1].first , input[B - 1].second};
}
