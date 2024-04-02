class Solution {
    int f(string &s,string &t,int i,int j,vector<vector<int>> &dp) {
        if(j==t.size()) return 1;
        if(i==s.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int res=0;
        if(s[i]==t[j]) res+=f(s,t,i+1,j+1,dp);
        res+=f(s,t,i+1,j,dp);
        return dp[i][j] = res;
    }
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(), vector<int> (t.size(),-1));
        return f(s,t,0,0,dp);
    }
};