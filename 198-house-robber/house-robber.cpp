class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size(), a=nums[0],b=-1,c;
        a=nums[0];
        if(1<n) b=max(nums[0], nums[1]);
        c=max(a,b);
        for(int i=2;i<nums.size();i++) {
            c=max(nums[i]+a, b);
            a=b; b=c;
        }
        return c;
    }
};