class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans=nums.size(),l=0,h=nums.size()-1;
        while(l<=h) {
            int m=(h-l)/2+l;
            if(nums[m]>=target) {
                ans=m; h=m-1;
            }
            else l=m+1;
        }
        return ans;
    }
};