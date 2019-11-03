/*
Monocarp and Bicarp live in Berland, where every bus ticket consists of N digits (N is an even number). During the evening walk Monocarp and Bicarp found a ticket where some of the digits have been erased. The number of digits that have been erased is even. Monocarp and Bicarp have decided to play a game with this ticket. Monocarp hates happy tickets, while Bicarp collects them. A ticket is considered happy if the sum of the first N/2 digits of this ticket is equal to the sum of the last N/2 digits. Monocarp and Bicarp take turns (and Monocarp performs the first of them). During each turn, the current player must replace any erased digit with any digit from 0 to 9. The game ends when there are no erased digits in the ticket. If the ticket is happy after all erased digits are replaced with decimal digits, then Bicarp wins. Otherwise, Monocarp wins. You have to determine who will win if both players play optimally. Find and return the winner of the game. 

Input Format:
The first and the only argument of input contains a string S, of N digits.

Output Format:
Return a string representing the winner.
If Monocarp wins: return "Monocarp" (without quotes).
If Bicarp wins: return "Bicarp" (without quotes).

Constraints:
1 <= N <= 2e5
0 <= S[i] <= 9

Examples:
Input 1:
    A = "0523"

Output 1:
    "Bicarp"

Explanation 1:
    There are no replaceable character and the condition is already satisfied, so Bicarp wins.

Input 2:
    A = "??"

Output 2:
    "Bicarp"

Explanation 2:
    Monocarp can choose any of the two '?'s and place any digit on it. Bicarp will simply choose the other '?' and place the same digit on it.

Input 3:
    "???00?"

Output 3:
    "Monocarp"

*/

string Solution::solve(string A) {
    int n = A.size();
    int leftSum, rightSum, leftCount, rightCount;
    leftSum = rightSum = leftCount = rightCount = 0;

    string output[] = {"Monocarp", "Bicarp"};
    for(int i = 0; i < n / 2; i++){
        if(A[i] == '?') {
            leftCount++;
            continue;
        }
        leftSum += (A[i] - '0');

    }
    for(int i = n / 2; i < n; i++){
        if(A[i] == '?') {
            rightCount++;
            continue;
        }
        rightSum += (A[i] - '0');

    }

    int Balance = leftSum - rightSum;
    int minCount = min(leftCount, rightCount);
    leftCount -= minCount;
    rightCount -= minCount;

    if(Balance == 0 and leftCount == 0 and rightCount == 0) return output[1];

    if(leftSum > rightSum and rightCount > leftCount){
        if(9 * rightCount / 2 >= Balance and 9 * rightCount / 2 <= Balance) return output[1];
    }
    if(leftSum < rightSum and rightCount < leftCount){
        if(9 * leftCount / 2 >= abs(Balance) and 9 * leftCount / 2 <= abs(Balance)) return output[1];
    }
    return output[0];
    
}
