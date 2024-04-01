class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0,res=0;
        for(int r=0;r<nums.size()-1;) {
            res++;
            int far=0;
            for(int i=l;i<=r;i++) far=max(far,i+nums[i]);
            l=r+1,r=far;
        }
        return res;
    }
};