struct cell{
    int first, second, pro;
};

bool comp(cell a, cell b){
    return a.second < b.second;
}

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n  = startTime.size();
        vector<cell> input(n);

        for(int i = 0; i < n; i++){
            input[i].first = startTime[i];
            input[i].second = endTime[i];
            input[i].pro = profit[i];
        }
        sort(input.begin(), input.end(), comp);

        set<int> index;
        map<int,int> mp;

        for(int i = 0; i < n; i++){
            int st = input[i].first, ed = input[i].second, price = input[i].pro;
            auto it = index.lower_bound(st);
            auto it2 = index.lower_bound(ed);
            int best_till_now = 0;

            if(it2 == index.end()){
                if(index.size() > 0){
                    it2--;
                    if(*it2 > st) best_till_now = mp[*it2];
                }
            }
            else if(it2 == index.begin()){
                if(*it2 == ed){
                    best_till_now = mp[*it2];
                }
            }
            else{
                if(*it2 != ed){
                    it2--;
                }
                best_till_now = mp[*it2];
            }

            if(it == index.begin()){
                if(*it == st) {
                    int bestPrice = mp[*it];
                    mp[ed] = max(price + bestPrice, best_till_now);
                    index.insert(ed);
                }
                else{
                    index.insert(ed);
                    mp[ed] = max(price, best_till_now);
                }
            }
            else if(it == index.end()){
                if(index.size() > 0){
                    it--;
                    int bestPrice = mp[*it];
                    mp[ed] = max(price + bestPrice, best_till_now);
                    index.insert(ed);
                }
                else{
                    index.insert(ed);
                    mp[ed] = max(price, best_till_now);
                }
            }
            else{
                if(*it != st){
                    it--;
                }
                int bestPrice = mp[*it];
                mp[ed] = max(price + bestPrice, best_till_now);
                index.insert(ed);
            }

        }
        int ans = 0;
        for(auto x: mp){
            ans = max(ans, x.second);
        }
        return ans;
    }
};