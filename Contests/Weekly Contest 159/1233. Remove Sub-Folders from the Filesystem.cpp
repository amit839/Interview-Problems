bool comp(string a, string b){
    return a.size() < b.size();
}

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();
        sort(folder.begin(), folder.end(), comp);
        
        set<string> st;
        for(auto x: folder){
            string temp;
            bool found = true;
            for(int i = 0; i < x.size(); i++){
                temp += x[i];
                if(i + 1 == x.size() or x[i + 1] == '/') {
                    if(st.find(temp) != st.end()) {
                        found = false;
                        break;
                    }
                }     
            }   
            if(found) st.insert(x);
        }
        vector<string> output(st.begin(), st.end());
        return output;
    }
};