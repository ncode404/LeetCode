class Solution {
public:
    int longestDivisor(int n) {
        for(int i=2;i*i<=n;i++) {
            if(n%i==0) return n/i;
        }
        return 0;
    }
    int integerBreak(int n) {
        vector<int> dp = {0,1,2,4};
        for(int i=4;i<=n;i++) {
            int res = longestDivisor(dp[i-1]);
            dp.push_back(dp[i-1]+res);
        }
        return dp[n-1];
    }
};