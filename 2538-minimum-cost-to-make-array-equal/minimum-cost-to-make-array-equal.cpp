class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long i,n=nums.size();
        vector<pair<int,int>> v(n);
        for(i=0;i<n;i++) 
            v[i].first=nums[i], v[i].second=cost[i];

        sort(v.begin(), v.end());
        long long pre[n], suf[n], j=0, t=0;

        pre[0]=v[0].second;
        for(i=1;i<n;i++) pre[i]=pre[i-1]+v[i].second;
        suf[n-1]=v[n-1].second;
        for(i=n-2;i>=0;i--) suf[i]=suf[i+1]+v[i].second;

        for(auto i:v) {
            t += ((long long)i.second*(long long)abs(1-i.first));
        }
        long long res=t;
        for(i=2;i<=1e6;i++) {

            while(j<n && v[j].first<i) j++;
            if(j>0) t += pre[j-1];
            if(j<n) t -= suf[j];

            res=min(res,t);
        }
        return res;
    }
};