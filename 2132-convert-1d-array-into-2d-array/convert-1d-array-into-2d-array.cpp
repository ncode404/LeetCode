class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& o, int m, int n) {
        if((m*n) != (o.size())) return {};
        vector<vector<int>> res(m, vector<int> (n));
        int t=0, u=0;
        for(int i=0;i<o.size();i++) {
            res[t][u++]=o[i];
            if(u==n) u=0, t++;
        }
        return res;
    }
};