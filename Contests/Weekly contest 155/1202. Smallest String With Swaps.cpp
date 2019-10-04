// Link to the problem statement: https://leetcode.com/contest/weekly-contest-155/problems/smallest-string-with-swaps/

const int N = 1e5 + 10;
int arr[N],siz[N];

int root(int i){
    while(arr[i]!=i){
		arr[i]=arr[arr[i]];
        i=arr[i];
    }
    return i;
}
bool find(int x, int y){
    return root(x)==root(y);
}

void join(int x, int y){
    int roota=root(x),rootb=root(y);
    if(roota==rootb) return;
    if(siz[roota]<siz[rootb]){
        arr[roota]=arr[rootb];
        siz[rootb]+=siz[roota];
    }
    else {
        arr[rootb]=arr[roota];
        siz[roota]+=siz[rootb];
    }
}

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        const int n = s.size();
        for(int i = 0; i < n; i++){
            arr[i] = i;
            siz[i] = 1;
        }
        for(auto x : pairs){
            join(x[0], x[1]);
        }
        map<int, set<pair<char,int>>> mp;
        for(int i = 0; i < n; i++){
            mp[root(i)].insert({s[i], i});
        }
        for(auto x: mp){
            vector<int> pos;
            for(auto y: x.second){
                pos.push_back(y.second);
            }
            sort(pos.begin(), pos.end());
            int ct = 0;
            for(auto y: x.second){
                s[pos[ct++]] = y.first;
            }
        }
        return s;
    }
};