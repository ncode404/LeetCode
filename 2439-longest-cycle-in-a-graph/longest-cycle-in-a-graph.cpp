class dsu {
public:
    vector<int> pr;
    int counter=0;
    dsu(int n) {
        pr.resize(n);
        for(int i=0;i<n;i++) {
            pr[i]=i;
        }
    }
    int l(int n) {
        if(n==pr[n]) return n;
        counter++;
        return n=l(pr[n]);
    }
    void m(int a, int b) {
        pr[b]=a;
    }
};

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        dsu d(edges.size());
        int res=-1;
        for(int i=0;i<edges.size();i++) {
            if(edges[i]==-1) continue;
            d.counter=0;
            if(d.l(edges[i])==i) {
                res=max(res, d.counter+1);
            }
            else d.m(edges[i],i);
        }
        return res;
    }
};