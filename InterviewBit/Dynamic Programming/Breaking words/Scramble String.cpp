// https://www.interviewbit.com/problems/scramble-string/

int checkString(map<string,int>& mp, string A, string B){
    if(A == B) return 1;
    
    string hash = A + '.' + B;
    
    if(mp.find(hash) != mp.end()){
        return mp[hash];
    }
    
    int n = A.size();
    map<char,int> freq;
    
    for(auto x: A){
        freq[x]++;
    }
    for(auto x: B){
        freq[x]--;
    }
    
    for(auto x: freq){
        if(x.second != 0){
            mp[hash] = 0;
            return 0;
        }
    }
    int result = 0;
    
    for(int i = 0; i < n - 1; i++){
        result = checkString(mp, A.substr(0,i + 1), B.substr(0, i + 1)) and checkString(mp, A.substr(i + 1), B.substr(i + 1));
        
        if(result){
            return mp[hash] = 1;
        }
        result = checkString(mp, A.substr(0, i + 1), B.substr(n - i - 1)) and checkString(mp, A.substr(i + 1), B.substr(0, n - i - 1));
        if(result){
            return mp[hash] = 1;
        }
    }
    return mp[hash] = 0;
}
 
int Solution::isScramble(const string A, const string B) {
    map<string, int> mp;
    
    return checkString(mp, A, B);
}