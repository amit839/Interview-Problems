// Link to the problem statement : https://leetcode.com/problems/contains-duplicate-iii/

// Time complexity -> O(n^2)
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        for(int i = 0; i < n ;i++){
            for(int j = i+1;j<=min(n-1,i+k);j++){
                long long val = abs((long long)nums[j]-nums[i]);
                
                if(val<=t) return true;
            }
        }
        return false;
    }
};

//  Time complexity -> O(n * log(n))

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        
        int n = nums.size();
    
        if(n < 2) return false;

        vector<pair<long long,long long>> arr(n);

        for(int i = 0; i < n; i++){
            arr[i].first = nums[i];
            arr[i].second = i;
        }
        sort(arr.begin(), arr.end());

        int i = 0, j = 0;
        set<int> st;
        while(i <= j and j < n){
            if(arr[j].first - arr[i].first <= t*1L){
                auto it = st.lower_bound(arr[j].second);
                if(it != st.end()){
                    if(abs(*it - arr[j].second) <= k) return true;
                }
                if(st.size() > 1 or(st.size() == 1 and it == st.end())){
                    it--;
                    if(abs(*it - arr[j].second) <= k) return true;    
                }
                st.insert(arr[j].second);
                j++;
            }
            else{
                st.erase(arr[i].second);
                i++;
            }
        }
        return false;
    }
};

