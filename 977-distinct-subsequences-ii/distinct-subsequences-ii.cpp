const int mod = 1e9+7;
class Solution {
public:
    int distinctSubseqII(string s) {
        int n=s.size();
        vector<long long> dp(n);
        dp[0]=2;
        for(int i=1;i<n;i++) {
            long long dup=0;
            for(int j=i-1;j>0;j--) {
                if(s[i]==s[j]) {
                    dup=dp[j-1];
                    break;
                }
            }
            if(!dup && i!=0 && s[0]==s[i]) dup=1;
            dp[i] = (2*dp[i-1])%mod;
            dp[i] = (dp[i]-dup+mod)%mod;
        }
        if(dp[n-1]<=0) dp[n-1]+=mod;
        return dp[n-1]-1;
    }
};