class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<pair<int,int>> v;
        int c=1,i,ans=0;
        for(i=1;i<nums.size();i++) {
            if(nums[i]==nums[i-1]) c++;
            else {
                v.push_back({nums[i-1],c});
                c=1;
            }
        }
        v.push_back({nums[i-1],c});
        for(i=0;i<v.size();i++) {
            if(v[i].first==1) {
                ans=max(ans,v[i].second);
                
                if(i+2<v.size() && v[i+1].second==1)
                    ans=max(ans,v[i].second+v[i+2].second);
            }
        }
        if(ans == nums.size()) return ans-1;
        return ans;
    }
};