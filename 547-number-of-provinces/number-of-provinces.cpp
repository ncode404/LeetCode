class dsu {
public:
    vector<int> p,s;
    dsu(int n) {
        p.resize(n);
        s.resize(n,1);
        for(int i=0;i<n;i++) p[i]=i;
    }
    int l(int n) {
        if(n==p[n]) return n;
        return p[n]=l(p[n]);
    }
    void m(int a,int b) {
        int x=l(a),y=l(b);
        if(x!=y) {
            if(s[x]<s[y]) swap(x,y);
            s[x]+=s[y];
            p[y]=x;
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& m) {
        dsu d(m.size());
        for(int i=0;i<m.size();i++) {
            for(int j=i+1;j<m.size();j++) {
                if(m[i][j]) d.m(i,j);
            }
        }
        int res=0;
        for(int i=0;i<m.size();i++) {
            if(d.l(i)==i) res++;
        }
        return res;
    }
};