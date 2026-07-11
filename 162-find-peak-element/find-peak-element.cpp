class Solution {
    int check(int mid,vector<int> &nums) {
        if(mid==nums.size()-1) {
            if(nums[mid]>nums[mid-1]) return 1; /// to check neighbours
            return 0;
        }
        if(nums[mid]>nums[mid+1]) return 1;
        return 0;
    }
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1) return 0;

        int low=0,high=nums.size()-1,ans=0;
        while(low<=high) {
            int mid=low+(high-low)/2;
            if(check(mid,nums)) {
                ans=mid; high=mid-1;
            } else low=mid+1;
        }
        return ans;
    }
};