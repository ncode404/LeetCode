class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j=0;
        for(int i=0;i<nums.size();i++) {
            while(j<nums.size() && nums[j]!=val) j++;
            if(j<nums.size() && nums[i]!=val && j<i) {
                swap(nums[i],nums[j]); j++;
            }
        }
        return j;
    }
};