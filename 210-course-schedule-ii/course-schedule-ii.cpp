class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& v) {
        unordered_map<int,vector<int>> adj;
        int inD[n];
        memset(inD, 0, sizeof(inD));
        for(auto i:v) {
            adj[i[1]].push_back(i[0]);
            inD[i[0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++) {
            if(!inD[i]) q.push(i);
        }
        vector<int> res;
        while(!q.empty()) {
            int node=q.front();
            q.pop();
            res.push_back(node);

            for(auto it: adj[node]) {
                inD[it]--;
                if(!inD[it]) q.push(it);
            }
        }
        if(res.size()!=n) return {};
        return res;
    }
};