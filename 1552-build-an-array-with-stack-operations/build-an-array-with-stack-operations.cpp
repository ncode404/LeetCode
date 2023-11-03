class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int t=1,i;
        for(i=0;i<target.size();i++) {
            res.push_back("Push");
            if(target[i]!=t) {
                res.push_back("Pop");
                i--;
            }
            t++;
        }
        return res;
    }
};