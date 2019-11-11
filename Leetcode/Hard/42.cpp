class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftGreater(n), rightGreater(n);
        
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() and height[st.top()] <= height[i]) st.pop();
            if(!st.empty()) leftGreater[i] = height[st.top()];
            if(st.empty()) st.push(i);
        }
        st = stack<int>();
        for(int i = n - 1; i > -1; i--){
            while(!st.empty() and height[st.top()] <= height[i]) st.pop();
            if(!st.empty()) rightGreater[i] = height[st.top()];    
            if(st.empty()) st.push(i);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            int minval = min(leftGreater[i], rightGreater[i]);
            minval -= height[i];
            if(minval > 0) ans += minval;
        }
        return ans;
    }
};