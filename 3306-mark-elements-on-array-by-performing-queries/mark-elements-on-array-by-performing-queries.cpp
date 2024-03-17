class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<pair<int,int>> v;
        long long sum=0,ind=0;
        for(auto i:nums) sum+=i, v.push_back({i,ind++});
        sort(v.begin(),v.end());
        unordered_map<int,bool> mp;
        vector<long long> res;
        int j=0;
        for(auto i:queries) {
            if(!mp[i[0]]) sum-=nums[i[0]], mp[i[0]]=1;
            int k=i[1];
            while(k--) {
                while(j<nums.size() && mp[v[j].second]) j++;
                if(j>=nums.size()) break;
                sum-=v[j].first; mp[v[j].second]=1;
            }
            res.push_back(sum);
        }
        return res;
    }
};