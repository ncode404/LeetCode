class Solution {
public:
    int rob(vector<int>& nums) {
        int i,n=nums.size();
        int dp[n];
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        
        dp[0]=nums[0],dp[1]=max(nums[0],nums[1]);
        for(i=2;i<n;i++) {
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int> m;
        int p=-1,q=INT_MAX;
        for(auto i:nums) {
            m[i]+=i;
            p=max(p,i);
            q=min(q,i);
        }
        vector<int> v;
        for(int i=q;i<=p;i++) 
            v.push_back(m[i]);
        return rob(v);
    }
};