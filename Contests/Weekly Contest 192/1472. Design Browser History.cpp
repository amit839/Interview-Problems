// https://leetcode.com/contest/weekly-contest-192/problems/design-browser-history/

class BrowserHistory {
public:
    vector<string> myurl;
    int id;
    
    BrowserHistory(string homepage) {
        myurl.clear();
        id = 0;
        myurl.push_back(homepage);
    }
    
    void visit(string url) {
        while(myurl.size() > id + 1) myurl.pop_back();
        myurl.push_back(url);
        id++;
    }
    
    string back(int steps) {
        id = max(0, id - steps);
        return myurl[id];
    }
    
    string forward(int steps) {
        id = min(id + steps, (int)myurl.size() - 1);
        return myurl[id];
    }
};
