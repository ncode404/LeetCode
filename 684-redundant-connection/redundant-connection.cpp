class dsu {
public:
    vector<int> p,s;
    dsu(int n) {
        p.resize(n);
        s.resize(n);
        for(int i=0;i<n;i++) {
            p[i]=i; s[i]=1;
        }
    }
    int l(int node) {
        if(node==p[node]) return node;
        return node=l(p[node]);
    }
    int merge(int a, int b) {
        int x=l(a), y=l(b);
        if(x==y) return x;
        if(s[x]<s[y]) swap(x,y);
        s[x]+=s[y];
        p[y]=x;
        return x;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        dsu d(edges.size()+1);
        for(auto i:edges) {
            if(d.l(i[0])!=d.l(i[1])) {
                d.merge(i[0], i[1]);
            }
            else return i;
        }
        return {};
    }
};