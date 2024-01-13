class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> m1,m2;
        for(int i=0;i<s.size();i++) {
            m1[s[i]]++; m2[t[i]]++;
        }
        int res=0;
        for(char c='a';c<='z';c++) {
            if(m2[c]<m1[c])
                res+=abs(m1[c]-m2[c]);
        }
        return res;
    }
};