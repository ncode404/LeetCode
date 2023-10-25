class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> m;
        for(auto i:wordDict) {
            reverse(i.begin(), i.end());
            m[i]++;
        }

        vector<bool> dp(s.size(),0);
        for(int i=0;i<s.size();i++) {
            string temp;
            for(int j=i;j>=0;j--) {
                temp+=s[j];
                if(m[temp]) {
                    if(j==0) {
                        dp[i]=1; break;
                    }
                    else {
                        if(dp[j-1]==1) {
                            dp[i]=1; break;
                        }
                    }
                }
            }
        }
        return dp[s.size()-1];
    }
};