class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        set<pair<int,int>> mp;
        int n = coordinates.size();
        int a = coordinates[0][0], b = coordinates[0][1];
        for(int i = 1; i < n; i++){
            int x = coordinates[i][0], y = coordinates[i][1];
            int num = y - b, den = x - a;
            int gg = __gcd(num, den);
            num /= gg;
            den /= gg;
            if(den < 0){
                num *= -1;
                den *= -1;
            }
            mp.insert({num, den});
        }
        return mp.size() == 1;
    }
};