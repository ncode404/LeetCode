class Solution {
public:
    int rob(vector<int>& nums) {
        int a=nums[0],b=a,n=nums.size();
        if(n>1) b=max(nums[1],b);
        for(int i=2;i<n;i++) {
            if(i%2==0) a=max(b,a+nums[i]);
            else b=max(a,b+nums[i]);
        } 
        return max(a,b);
    }
};