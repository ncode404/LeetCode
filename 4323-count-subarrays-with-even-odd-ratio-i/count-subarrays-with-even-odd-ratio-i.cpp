class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int res=0;
        for(int i=0;i<nums.size();i++) {
            int e=0,o=0;
            for(int j=i;j<nums.size();j++) {
                if(nums[j]%2) o++;
                else e++;
                if(e*b<=o*a) res++;
            }
        }
        return res;
    }
};