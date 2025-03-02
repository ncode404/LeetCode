class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& x, vector<vector<int>>& y) {
        vector<vector<int>> res;
        int i=0,j=0;
        while(i<x.size() && j<y.size()) {
            if(x[i][0]==y[j][0]) {
                res.push_back({x[i][0], x[i][1]+y[j][1]});
                i++, j++;
            }
            else if(x[i][0]>y[j][0]) res.push_back(y[j++]);
            else res.push_back(x[i++]);
        }
        while(i<x.size()) res.push_back(x[i++]);
        while(j<y.size()) res.push_back(y[j++]);
        return res;
    }
};