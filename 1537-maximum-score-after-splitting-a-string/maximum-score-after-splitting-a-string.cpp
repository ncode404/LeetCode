class Solution {
public:
    int maxScore(string s) {
        int l=(s[0]=='0'), r=0, res=0;
        for(int i=1;i<s.size();i++) {
            r+=(s[i]=='1');
        }
        res=l+r;
        for(int i=1;i<s.size()-1;i++) {
            if(s[i]=='0') l++;
            else r--;

            res=max(res,l+r);
        }
        return res;
    }
};