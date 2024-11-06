class Solution {
    int bit(int x) {
        return __builtin_popcount(x);
    }
public:
    bool canSortArray(vector<int>& nums) {
        for(int i=1;i<nums.size();i++) {
            int j=i;
            while(j>0 && nums[j]<nums[j-1] && bit(nums[j]) == bit(nums[j-1])) {
                swap(nums[j], nums[j-1]);
                j--;
            }
        }
        return is_sorted(nums.begin(), nums.end());
    }
};