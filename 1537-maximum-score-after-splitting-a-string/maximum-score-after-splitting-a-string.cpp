class Solution {
public:
    int maxScore(string s) {
        int leftZ=0, rightO=0, res=0;
        for(int i=0;i<s.size();i++) {
            if(i==0) leftZ=(s[i]=='0');
            else rightO = rightO+(s[i]=='1');
        }
        res=leftZ+rightO;
        for(int i=1;i<s.size()-1;i++) {
            if(s[i]=='0') leftZ++;
            else rightO--;

            res=max(res,leftZ+rightO);
        }
        return res;
    }
};