class Solution {
    vector<int> dp;
    int f(string &s,int i) {
        if(i==s.size()) return 1;
        if(dp[i]!=-1) return dp[i];
        
        int res=0;
        if(s[i]!='0') {
            if(i+1<s.size() && ((s[i]-'0')*10+(s[i+1]-'0'))<=26)
            res += f(s,i+2);

            res += f(s,i+1);
        }

        return dp[i]=res;
    }
public:
    int numDecodings(string s) {
        if(s[0]=='0') return 0;
        dp.resize(s.size()+1,-1);
        return f(s,0);
    }
};