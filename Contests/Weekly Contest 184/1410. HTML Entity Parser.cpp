// https://leetcode.com/contest/weekly-contest-184/problems/html-entity-parser/

class Solution {
public:
    string entityParser(string text) {
        int n = text.size();
        string output;
        
        for(int i = 0; i < n; i++){
            if(text[i] == '&'){
                string t;
                bool f = 0;
                for(int j = i + 1; j < n; j++){
                    t += text[j];
                    if(t.size() == 3){
                        if(t == "gt;"){
                            output += '>';
                            i = j;
                            break;
                        }
                        else if(t == "lt;"){
                            output += '<';
                            i = j;
                            break;
                        }
                    }
                    if(t.size() == 4){
                        if(t == "amp;"){
                            output += '&';
                            i = j;
                            break;
                        }
                    }
                    if(t.size() == 5){
                        if(t == "quot;"){
                            output += '"';
                            i = j;
                            break;
                        }
                        if(t == "apos;"){
                            output += "'";
                            i = j;
                            break;
                        }
                    }
                    if(t.size() == 6){
                        if(t == "frasl;"){
                            output += '/';
                            i = j;
                            break;
                        }
                    }
                    if(t.size() > 6){
                        f = 1;
                        break;
                    } 
                    
                } 
                if(f) output += text[i];
            }
            else output += text[i];
        }
        return output;
    }
};