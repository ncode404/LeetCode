class Solution {
public:
    int minimumRecolors(string b, int k) {
        vector<int> pre(b.size());
        pre[0]=(b[0]=='B');
        for(int i=1;i<b.size();i++) {
            pre[i]=pre[i-1]+(b[i]=='B');
        }
        int res=k-pre[k-1];
        for(int i=k;i<b.size();i++) {
            res=min(res,k-(pre[i]-pre[i-k]));
        }
        return res;
    }
};