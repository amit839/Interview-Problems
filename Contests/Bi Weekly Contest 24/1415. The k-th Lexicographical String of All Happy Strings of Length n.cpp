// 1415. The k-th Lexicographical String of All Happy Strings of Length n

class Solution {
public:
    
    void gen(int i, int n, vector<string>& num, string temp){
        if(i == n){
            num.push_back(temp);
            return;
        }
        if(temp[i - 1] == 'a'){
            gen(i + 1, n, num, temp + 'b');
            gen(i + 1, n, num, temp + 'c');
        }
        else if(temp[i - 1] == 'b'){
            gen(i + 1, n, num, temp + 'a');
            gen(i + 1, n, num, temp + 'c');
        }
        else if(temp[i - 1] == 'c'){
            gen(i + 1, n, num, temp + 'a');
            gen(i + 1, n, num, temp + 'b');
        }
        
    }
    
    string getHappyString(int n, int k) {
        vector<string> num;
        string temp;
        
        gen(1, n, num, temp + 'a');
        gen(1, n, num, temp + 'b');
        gen(1, n, num, temp + 'c');

        sort(num.begin(), num.end());
        
        if(k <= num.size()) return num[k - 1];
        else return "";
    }
};