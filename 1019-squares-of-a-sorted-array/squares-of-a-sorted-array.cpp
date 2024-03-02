class Solution {
    int bs(vector<int> &nums) {
        int l=0,r=nums.size()-1;
        while(l<=r) {
            int mid=(l+r)/2;
            if(nums[mid]>=0) r=mid-1;
            else l=mid+1;
        }
        return r+1;
    }
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l=bs(nums),r=l-1,n=nums.size();
        // return {l};
        vector<int> res;
        while(r>=0 || l<n) {
            if(r>=0 && l<n) {
                if(abs(nums[l])>abs(nums[r])) res.push_back(abs(nums[r])*abs(nums[r])), r--;
                else res.push_back(abs(nums[l])*abs(nums[l])), l++;
            }
            else if(r>=0) res.push_back(nums[r]*nums[r]), r--;
            else res.push_back(nums[l]*nums[l]), l++;
        }
        return res;
    }
};