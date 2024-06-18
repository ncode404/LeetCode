class Solution {
    int f(int i, vector<pair<int,int>> &vec) {
        int l=0,r=vec.size()-1;
        while(l<=r) {
            int m=(l+r)/2;
            if(vec[m].first>i) r=m-1;
            else l=m+1;
        }
        return l;
    }
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        int res=0, x=INT_MIN;
        vector<pair<int,int>> vec;
        for(int i=0;i<d.size();i++) vec.push_back({d[i],p[i]});
        sort(vec.begin(), vec.end());

        vector<int> dp;
        for(auto i:vec) {
            x=max(x,i.second);
            dp.push_back(x);
        }

        for(auto i:w) {
            int t=f(i,vec);
            if(t!=0) res+=dp[t-1];
        }
        return res;
    }
};