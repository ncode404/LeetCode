class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& v) {
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
        int cnt=0;
        while(!q.empty()) {
            int node=q.front();
            q.pop();
            cnt++;
            for(auto it: adj[node]) {
                inD[it]--;
                if(!inD[it]) q.push(it);
            }
        }
        if(cnt==n) return 1;
        return 0;
    }
};