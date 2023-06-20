class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size(),i,p=0,q=2*k;
        vector<int> ans(n);

        long long s=0;
        for(i=0;i<n && i<q;i++) s+=nums[i];

        for(i=0;i<n;i++) {
            if(i<k || (i+k)>=n) ans[i]=-1;
            else {
                s+=nums[q++]; ans[i]=(s/(2*k+1)); s-=nums[p++];
            }
        }
        return ans;
    }
};