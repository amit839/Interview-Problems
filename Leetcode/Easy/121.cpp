class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        
        int ans = 0, minVal = prices[0], n = prices.size();
        
        for(int i = 1; i < n; i++){
            if(prices[i] > minVal){
                ans = max(ans, prices[i] - minVal);
            }
            minVal = min(minVal, prices[i]);
        }
        return ans;
    }
};