/*
Given three integers A, B and C. Return the maximum possible value of A ^ D, such that D is an integar in range [B, C]. Note: ^ repersents BITWISE xor. Note: A single testfile may contain multiple testcases upto 10^5. 

Input Format
The first argument given is the integer A.
The second argument given is the integer B.
The third argument given is the integer C.

Output Format
Return the maximum possible value of A ^ D, such that D is an integar in range [B, C].

Constraints
1 <= A, B, C <= 10^9

For Example
Input 1:
    A = 2
    B = 1
    C = 10
Output 1:
    11
Explaination 1:
    For D = 9, A ^ D = 11, which is maximum for any D in range [1, 10]

Input 2:
    A = 3
    B = 5
    C = 6
Output 2:
    6

*/

int Solution::solve(int A, int B, int C) {
    int D = 0;
    for(int i = 30; i >= 0; i--){
        int bitI = (1 << i);
        if(A & bitI){
            if(i == 0){
                if(D < B){
                    D |= bitI;
                }
            }
            else{
                if((D | (bitI - 1)) >= B){
                    continue;  
                }
                D |= bitI;
            }
        }
        else{
            if((D | bitI) <= C){
                D |= bitI;
            }
        }
    }
    return A ^ D;
}