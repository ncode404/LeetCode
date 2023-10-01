class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int res=0,i,j;
        for(i=1;i<=k;i++) m[i]++;
        
        for(i=nums.size()-1;i>=0;i--) {
            res++;
            
            if(nums[i]>k) continue;
            m.erase(nums[i]);
            if(m.empty()) break;
        }
        return res;
    }
};