class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& p, int w) {
        map<int,int> m;
        for(auto i:p) m[i[0]]++;
        int t=-1, res=0;
        for(auto i:m) {
            if(i.first<=t) continue;
            t=i.first+w, res++;
        }
        return res;
    }
};