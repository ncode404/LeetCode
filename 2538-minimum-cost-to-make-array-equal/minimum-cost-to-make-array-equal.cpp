class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();i++) {
            v.push_back({nums[i], cost[i]});
        }
        sort(v.begin(), v.end());
        long long n=nums.size(), t=0, pre[n], suf[n],i;
        pre[0]=v[0].second; suf[n-1]=v[n-1].second;
        for(i=1;i<n;i++) {
            pre[i]=pre[i-1]+v[i].second;
        }
        for(i=n-2;i>=0;i--) {
            suf[i]=suf[i+1]+v[i].second;
        }
        for(auto i:v) {
            t+=((long long)i.second*(long long)(i.first-1));
        }
        long long res=t, j=0;

        for(int i=2;i<1e6;i++) {
            while(j<n && v[j].first<i) j++;
            if(j>0) t+=pre[j-1];
            if(j<n) t-=suf[j];

            res=min(res,t);
        }
        return res;
    }
};