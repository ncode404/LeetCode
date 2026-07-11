class Solution {
    int check(int mid,vector<int> &nums) {
        if(mid==nums.size()-1) {
            if(nums[mid]>nums[mid-1]) return 1;
            return 0;
        } else if(mid==0) {
            if(nums[mid]>nums[mid+1]) return 1;
            return 0;
        }
        else if(nums[mid]>nums[mid+1]) return 1;
        return 0;
    }
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1) return 0;

        int low=0,high=nums.size()-1,ans=0;
        while(low<=high) {
            int mid=low+(high-low)/2;
            cout<<low<<" "<<mid<<" "<<high<<" "<<ans<<"\n";
            if(check(mid,nums)) {
                ans=mid; high=mid-1;
            } else low=mid+1;

            cout<<low<<" "<<mid<<" "<<high<<" "<<ans<<"\n";
        }
        return ans;
    }
};