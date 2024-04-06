class Solution {
    vector<vector<int>> dp;
    int lcs(string &s,string &t,int i,int j) {
        if(i==s.size()||j==t.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int res=0;
        if(s[i]==t[j]) res=max(res,1+lcs(s,t,i+1,j+1));
        res=max({res,lcs(s,t,i+1,j),lcs(s,t,i,j+1)});
        return dp[i][j]=res;
    }
public:
    int minDistance(string s, string t) {
        dp.resize(s.size()+1,vector<int> (t.size()+1,-1));
        return s.size()+t.size()-2*lcs(s,t,0,0);
    }
};