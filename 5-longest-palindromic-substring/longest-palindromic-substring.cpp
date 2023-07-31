class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>> dp(s.size(), vector<int> (s.size(),0));
        int i,j,x=0,y=0;
        for(i=0;i<s.size();i++) {
            dp[i][i]=1;
            if(i>0) {
                if(s[i-1]==s[i])
                {dp[i-1][i]=1; x=i-1,y=i;}
            }
        }
        for(i=2;i<s.size();i++) {
            for(j=0;j<s.size()-i;j++) {
                if(s[j]==s[j+i] && dp[j+1][j+i-1]==1)
                {dp[j][j+i]=1; x=j,y=j+i;}
            } 
        }
        string ans;
        for(i=x;i<=y;i++) ans+=s[i];
        return ans;
    }
};