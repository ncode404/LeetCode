class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        for(int i=matrix.size()-2;i>=0;i--) {
            for(int j=0;j<matrix[0].size();j++) {
                int t=INT_MAX;
                if(j-1>=0) t=min(t,matrix[i+1][j-1]);
                t=min(t,matrix[i+1][j]);
                if(j+1<matrix[0].size()) t=min(t,matrix[i+1][j+1]);
                matrix[i][j]+=t;
            }
        }
        return *min_element(matrix[0].begin(), matrix[0].end());
    }
};