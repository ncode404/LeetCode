class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size()) return 0;
        int c=0,t=0;
        unordered_map<char,int> sm,gm;
        for(auto i:s) sm[i]++;
        for(auto i:goal) gm[i]++;

        if(sm!=gm) return 0;
        for(int i=0;i<s.size();i++) {
            if(s[i]!=goal[i]) c++;
            if(sm[s[i]]>1) t++;
        }
        if(c==2) return 1;
        else if(c!=0) return 0;
        return t!=0;
    }
};