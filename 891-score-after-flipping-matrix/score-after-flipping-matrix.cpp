class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        for(int i=0;i<n;i++) {
            if(grid[i][0]==0) {
                for(int j=0;j<m;j++) {
                    grid[i][j]^=1;
                }
            }
        }
        int res=0, l=m-1;
        for(int i=0;i<m;i++) {
            int c1=0, c2=0;
            for(int j=0;j<n;j++) {
                if(grid[j][i]==1) c1++;
                else c2++;
            }
            // cout<<c1<<" "<<c2<<"\n";
            res += (int)pow(2,l)*max(c1,c2);
            l--;
        }
        return res;
    }
};