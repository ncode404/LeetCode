class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        set<pair<int,int>> st;
        for(int i=0;i<grid.size();i++) {
            int p=0;
            for(int j=0;j<grid[0].size();j++)
                if(grid[i][j]) p++;
            if(p>1) {
                for(int j=0;j<grid[0].size();j++)
                if(grid[i][j]) st.insert({i,j});
            }
        }
        for(int i=0;i<grid[0].size();i++) {
            int p=0;
            for(int j=0;j<grid.size();j++)
                if(grid[j][i]) p++;
            if(p>1) {
                for(int j=0;j<grid.size();j++)
                if(grid[j][i]) st.insert({j,i});
            }
        }
        return st.size();
    }
};