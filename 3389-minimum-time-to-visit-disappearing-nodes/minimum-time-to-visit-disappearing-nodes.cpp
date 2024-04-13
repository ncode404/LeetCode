#define pint vector<int>
class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
    }
    vector<int> minimumTime(int n, vector<vector<int>>& e, vector<int>& d) {
        vector<int> res(n,INT_MAX);
        priority_queue<pint,vector<pint>,greater<pint>> pq;
        
        unordered_map<int,vector<pint>> adj;
        for(auto i:e) {
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        
        res[0]=0;
        pq.push({0,0,0});
        while(!pq.empty()) {
            auto it=pq.top();
            int cost=it[0],node=it[1],wt=it[2];
            pq.pop();
            if(wt>=d[node] || cost>res[node]) continue;
            for(auto x:adj[node]) {
                if(wt+x[1]<d[x[0]] && x[1]+cost<res[x[0]]) {
                    res[x[0]]=x[1]+cost;
                    pq.push({res[x[0]],x[0],wt+x[1]});
                }
            }
        }
        
        for(int i=0;i<n;i++) {
            if(res[i]==INT_MAX) res[i]=-1;
        }
        return res;
    }
};