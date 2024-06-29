class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int,set<int>> res;
        unordered_map<int,vector<int>> adj;
        vector<int> inD(n);
        for(auto i:edges) adj[i[0]].push_back(i[1]), inD[i[1]]++;
        queue<int> q;
        for(int i=0;i<n;i++) {
            if(!inD[i]) q.push(i);
        }
        while(!q.empty()) {
            int node=q.front();
            q.pop();
            for(auto i:adj[node]) {
                inD[i]--;
                res[i].insert(node);
                for(auto j:res[node]) res[i].insert(j);

                if(!inD[i]) q.push(i);
            }
        }
        vector<vector<int>> ans(n);
        for(auto i:res) {
            for(auto j:res[i.first]) ans[i.first].push_back(j);
        }
        return ans;
    }
};