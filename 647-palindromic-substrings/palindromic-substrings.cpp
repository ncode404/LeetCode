class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(),0));
        int i,j,ans=s.size();
        for(i=0;i<s.size();i++) {
            dp[i][i]=1;
            if(i>0) {
                if(s[i-1]==s[i]) {
                    dp[i-1][i]=1; ans++;
                }
            }
        }
        for(i=2;i<s.size();i++) {
            for(j=0;j<s.size()-i;j++) {
                if(s[j]==s[i+j] && dp[j+1][i+j-1])
                    {dp[j][j+i]=1; ans++;}
            }
        }
        return ans;
    }
};