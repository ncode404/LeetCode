class Solution {
public:
    int maximumLength(string s) {
        int i, c=1, res=-1;
        unordered_map<char,vector<int>> m;
        for(i=1; i<s.size(); i++) {
            if(s[i]==s[i-1]) c++;
            else {
                m[s[i-1]].push_back(c); c=1;
            }
        }
        m[s[i-1]].push_back(c);
        for(char c='a'; c<='z'; c++) {
            unordered_map<int,int> qa;
            for(auto i:m[c]) {
                if(i>2) qa[i]++, qa[i-1]+=2, qa[i-2]+=3;
                else if(i==2) qa[i]++, qa[i-1]+=2;
                else qa[i]++;
            }
            for(auto i:qa) {
                if(i.second>2) res=max(res,i.first);
            }
        }
        return res;
    }
};