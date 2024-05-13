class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        for(int i=1;i*i<=n;i++) dp[i*i]=1;
        for(int i=2;i<=n;i++) {
            if(dp[i]!=1) {
                for(int j=1;j<=i/2;j++) {
                    dp[i]=min(dp[i], dp[j]+dp[i-j]);
                }
            }
        }
        return dp[n];
    }
};