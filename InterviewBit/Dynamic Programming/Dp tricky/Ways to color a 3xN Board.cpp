// https://www.interviewbit.com/problems/ways-to-color-a-3xn-board/

const int MOD=1e9+7;

void add(int& a, int b){
    a+=b;
    if(a>=MOD)a-=MOD;
}

vector<vector<int>> confs;
bool can[40][40];
vector<vector<int>> dp;

void gen(vector<int>& v){
    if(v.size()==3){
        bool ok=true;
        for(int i=0;i<2;i++)if(v[i]==v[i+1]){
            ok=false;
            break;
        }
        if(ok)confs.push_back(v);
        return;
    }
    for(int i=1;i<=4;i++){
        v.push_back(i);
        gen(v);
        v.pop_back();
    }
}

int go(int n, int id){
    if(n==1)return 1;
    
    int& ans=dp[n][id];
    if(ans!=-1)return ans;
    
    ans=0;
    
    for(int i=0;i<36;i++)if(can[id][i]){
        add(ans,go(n-1,i));
    }
    
    return ans;
}

int Solution::solve(int n) {
    vector<int> v;
    gen(v);
    
    for(int i=0;i<36;i++){
        for(int j=0;j<36;j++){
            bool ok=true;
            for(int k=0;k<3;k++){
                if(confs[i][k]==confs[j][k]){
                    ok=false;
                    break;
                }
            }
            can[i][j]=ok;
        }
    }
    
    dp=vector<vector<int>>(n+5,vector<int>(40,-1));
    
    int ans=0;
    for(int i=0;i<36;i++){
        add(ans,go(n,i));
    }
    
    return ans;
}