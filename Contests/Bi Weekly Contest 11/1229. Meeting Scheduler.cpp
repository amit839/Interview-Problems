// https://leetcode.com/contest/biweekly-contest-11/problems/meeting-scheduler/

bool comp(vector<int>& a, vector<int>& b){
    return a[0] < b[0];
}

class Solution {
public:
    
    
    
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        int n = slots1.size(), m = slots2.size();
        int i = 0, j = 0;
        vector<int> output;
        
        sort(slots1.begin(), slots1.end(), comp);
        sort(slots2.begin(), slots2.end(), comp);
        
        while(i < n and j < m){
            if(slots1[i][0] >= slots2[j][1]) j++;
            else if(slots2[j][0] >= slots1[i][1]) i++;
            else{
                int a = max(slots1[i][0], slots2[j][0]), b = min(slots1[i][1], slots2[j][1]);
                if(b - a >= duration){
                    output.push_back(a);
                    output.push_back(a + duration);
                    return output;
                }
                if(slots1[i][1] > slots2[j][1]) j++;
                else i++;
            }
        }
        
        return output;
    }
};