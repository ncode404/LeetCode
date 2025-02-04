class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int t=nums[0], res=0;
        for(int i=1;i<nums.size();i++) {
            if(nums[i]>nums[i-1]) t+=nums[i];
            else {
                res=max(res,t);
                t=nums[i];
            }
        }
        return max(res,t);
    }
};