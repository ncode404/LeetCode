class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        queue<pair<int, vector<int>>> Q;
        Q.push({0,{0}});
        vector<vector<int>> res;
        while(!Q.empty()) {
            int node=Q.front().first;
            vector<int> temp=Q.front().second;
            Q.pop();
            if(node==graph.size()-1) {
                res.push_back(temp);
            }
            for(auto i:graph[node]) {
                temp.push_back(i);
                Q.push({i,temp});
                temp.pop_back();
            }
        }
        return res;
    }
};