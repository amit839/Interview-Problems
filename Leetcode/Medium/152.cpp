class Solution {
public:   
    
    int get_pro(vector<int>& a, int l, int r) {
        int cnt = 0, pro = 1;
        for (int i = l; i <= r; i++) {
            cnt += (a[i] < 0);
            pro *= a[i];
        }
        if (cnt % 2 == 0) return pro;
        if (l == r) return pro;
        int left = pro;
        int right = pro;
        for (int i = l; i <= r; i++) {
            right /= a[i];
            if (a[i] < 0) break;
        }
        for (int i = r; i >= l; i--) {
            left /= a[i];
            if (a[i] < 0) break;
        }
        return max(left, right);
    }
      
    int maxProduct(vector<int>& a) {
        int n = a.size();
        int ans = INT_MIN;
        if (find(a.begin(), a.end(), 0) != a.end()) ans = 0;
        int l = -1;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                if (l+1 <= i-1) v.push_back({l+1, i-1});
                l = i;
            }
        }
        if (l+1 < n) v.push_back({l+1, n-1});
        for (auto e : v) {
            ans = max(ans, get_pro(a, e.first, e.second));
        }
        return ans;
    }
};