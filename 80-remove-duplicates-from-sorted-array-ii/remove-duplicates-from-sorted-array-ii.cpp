class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=0, prev=nums[0], c=0;
        for(int i=1;i<nums.size();i++) {
            if(nums[i]!=nums[j]) {
                j++; swap(nums[i],nums[j]); c=0;
                prev=nums[j];
            }
            else {
                if(nums[i]==prev && c==0) {
                    c=1; j++; swap(nums[i],nums[j]);
                }
            }
        }
        return j+1;
    }
};