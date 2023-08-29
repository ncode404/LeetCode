class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size(), lb=-1, ub=-1, l,h;
        l=0,h=n-1;
        while(l<=h) {
            int m=(h-l)/2+l;
            if(nums[m]>=target) {
                if(nums[m]==target) lb=m; 
                h=m-1;
            }
            else l=m+1;
        }
        l=0,h=n-1;
        while(l<=h) {
            int m=(h-l)/2+l;
            if(nums[m]>target) h=m-1;
            else {
                if(nums[m]==target) ub=m; 
                l=m+1;
            }
        }
        return {lb,ub};
    }
};