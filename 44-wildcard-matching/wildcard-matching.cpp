class Solution {
    bool x=0;
    bool f(string &p,string &t,int i,int j, vector<vector<int>> &dp) {
    if(x==1) return 1;
    
    if(i==p.size() && j==t.size()) return 1;
    if(i==p.size()) return 0;
    if(j==t.size()) {
        while(i<p.size() && p[i]=='*') i++;
        if(i==p.size()) return 1;
        return 0;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    if(p[i]==t[j] || p[i]=='?') 
            return f(p,t,i+1,j+1,dp);
    else if(p[i]=='*') {
        for(int k=j;k<=t.size();k++) {
            bool b=f(p,t,i+1,k,dp);
            if(b==1) {
                x=1;
                return dp[i][j] = 1;
            }
        }
    }
    return dp[i][j] = 0;
    }
public:
    bool isMatch(string s, string p) {
        x=0;
        swap(s,p);
        vector<vector<int>> dp(s.size(), vector<int> (p.size(),-1));
        return f(s,p,0,0,dp);
    }
};