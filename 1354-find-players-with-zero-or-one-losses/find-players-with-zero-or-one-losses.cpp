class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,pair<int,int>> m;
        // {wins, loses}
        for(auto it:matches) {
            m[it[0]].first++; m[it[1]].second++;
        }
        vector<int> notLost, oneLost;
        for(auto it:m) {
            if(it.second.second==0) 
                notLost.push_back(it.first);
            else if(it.second.second==1)
                oneLost.push_back(it.first);
        }
        return {notLost, oneLost};
    }
};