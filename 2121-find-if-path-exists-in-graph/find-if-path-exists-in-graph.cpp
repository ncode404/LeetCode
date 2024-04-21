#define pb push_back
class Solution {
    vector<int> pr, sz;
    int find(int node) {
        if(node==pr[node]) return node;
        return pr[node]=find(pr[node]);
    }
    void merge(int a,int b) {
        int x=find(a), y=find(b);
        if(x!=y) {
            if(sz[a]<sz[b]) swap(a,b);
            sz[a]+=sz[b];
            pr[y]=x;
        }
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int dest) {
        for(int i=0;i<n;i++) {
            pr.pb(i); sz.pb(1);
        }
        for(auto i:edges)
            merge(i[0],i[1]);
        return find(source)==find(dest);
    }
};