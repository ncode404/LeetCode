class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int ans=0,i,j;
        map<vector<int>,int> m;
        vector<vector<int>> duplicate = grid;
        for(i=0;i<grid.size();i++) {
            for(j=i+1;j<grid[0].size();j++) {
                swap(duplicate[i][j],duplicate[j][i]);
            }
            m[duplicate[i]]++;
        }
        for(i=0;i<grid.size();i++) {
            ans+=m[grid[i]];
        }
        return ans;
    }
};