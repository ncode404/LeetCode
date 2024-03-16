class Solution {
public:
    string minimizeStringValue(string s) {
        unordered_map<char,int> m;
        string res,t;
        for(auto i:s) m[i]++;
        for(auto i:s) {
            if(i!='?') continue;
            char p;
            int mn=INT_MAX;
            for(char c='a';c<='z';c++) {
                if(m[c]<mn) {
                    mn=m[c]; p=c;
                }
            }
            t+=p;
            m[p]++;
        }
        sort(t.begin(),t.end());
        int j=0;
        for(auto i:s) {
            if(i!='?') res+=i;
            else res+=t[j++];
        }
        return res;
    }
};