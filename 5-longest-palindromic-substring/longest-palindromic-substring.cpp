class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size(), x=n-1, y=n-1;
        vector<vector<bool>> dp(n, vector<bool> (n,0));
        for(int i=0;i<n;i++) {
            dp[i][i]=1;
            if(i>0) {
                if(s[i-1]==s[i])
                dp[i-1][i]=1, x=i-1,y=i;
            }
        }
        for(int l=2;l<n;l++) {
            int j=l;
            for(int i=0;i<=n-l;i++) {
                if(s[i]==s[j] && dp[i+1][j-1])
                dp[i][j]=1, x=i, y=j;
                j++;
            }
        }
        return s.substr(x,y-x+1);
    }
};