class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k==1) {
            int size=s.size(),i;
            string t=s,res=s; s+=s;
            for(i=size;i<s.size();i++) {
                t.erase(t.begin()); t+=s[i];
                res=min(res,t);
            }
            return res;
        }
        sort(s.begin(),s.end());
        return s;
    }
};