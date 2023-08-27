class Solution {
public:
    int bs(vector<int> &nums,int l,int h,int target) {
        while(l<=h) {
            int m=(h-l)/2+l;
            if(nums[m]==target) return m;
            if(nums[m]>target) h=m-1;
            else l=m+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int findPeak=0, l=0, h=nums.size()-1;
        while(l<=h) {
            int m=(h-l)/2+l;
            if(nums[0]>nums[m]) {
                findPeak=m; h=m-1;
            }
            else l=m+1;
        }
        // cout<<findPeak;
        int res = bs(nums,0,findPeak-1,target);
        if(res!=-1) return res;
        res = bs(nums,findPeak,nums.size()-1,target);
        return res;
    }
};