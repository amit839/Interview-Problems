// https://leetcode.com/problems/design-a-leaderboard/

map<int,int> mp;
map<int, set<int>> st;

class Leaderboard {
public:
    
    Leaderboard() {
        map<int,int> ff;
        map<int, set<int>> ss;
        mp = ff;
        st = ss;
    }

    void addScore(int playerId, int score) {
        int val = mp[playerId];
        st[val].erase(playerId);
        val += score;
        mp[playerId] = val;
        st[val].insert(playerId);
    }

    int top(int K) {
        int sum = 0;
        for(auto it = st.rbegin(); it != st.rend(); it++){
            int count = it->second.size();
            int val = it->first;
            if(K > count){
                K -= count;
                sum += val * count;
            }
            else {
                sum += val * K;
                K = 0;
            }
            if(K < 1) break;
        }
        return sum;
    }

    void reset(int playerId) {
        int val = mp[playerId];
        st[val].erase(playerId);
        val = 0;
        mp[playerId] = val;
        st[val].insert(playerId);
    }
};


/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */