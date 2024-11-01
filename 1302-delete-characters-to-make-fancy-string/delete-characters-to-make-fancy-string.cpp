class Solution {
public:
    string makeFancyString(string s) {
        string res;
        for(int i=0;i<s.size();i++) {
            if(i-1>=0 && i-2>=0 && s[i]==s[i-1] && s[i]==s[i-2]) continue;
            res+=s[i];
        }
        return res;
    }
};