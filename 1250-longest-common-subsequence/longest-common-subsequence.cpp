class Solution {
public:
    int f(string &s, string &t, int i, int j, vector<vector<int>> &dp) {
        if(i==s.size() || j==t.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j] = 1+f(s,t,i+1,j+1,dp);
        else return dp[i][j] = max(f(s,t,i+1,j,dp),f(s,t,i,j+1,dp));
    }
    int longestCommonSubsequence(string s, string t) {
        vector<vector<int>> dp(s.size()+1, vector<int> (t.size()+1, -1));
        return f(s,t,0,0, dp);
    }
};