class Solution {
public:
    int getLucky(string s, int k) {
        int res=0;
        string x;
        for(auto i:s) x+=to_string((int)(i-'a'+1));
        while(k--) {
            res=0;
            for(auto i:x) res+=(int)(i-'0');
            x=to_string(res);
        }
        return res;
    }
};