class Solution {
public:
    int dp[301]={0};
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> m;
        for(auto i:wordDict) {
            reverse(begin(i),end(i));
            m[i]++;
        }

        int i,j,n=s.size();
        for(i=0;i<n;i++) {
            string t;
            for(j=i;j>=0;j--) {
                t+=s[j];
                if(m[t]) {
                    if(j==0||(j>0 && dp[j-1]))
                    {dp[i]=1; break;}
                }
            }
        }
        return dp[n-1];
    }
};