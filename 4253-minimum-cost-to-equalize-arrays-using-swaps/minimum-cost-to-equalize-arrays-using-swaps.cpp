class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m1, m2;
        for(auto i:nums1) m1[i]++;
        for(auto i:nums2) m2[i]++;

        for(auto i:m1) if((i.second+m2[i.first])&1) return -1;
        for(auto i:m2) if((i.second+m1[i.first])&1) return -1;
        int res=0;
        for(auto i:m1) {
            int diff = abs(i.second-m2[i.first]);
            res+=diff/2;
        }

        if(res&1) res=res/2+1;
        else res=res/2;
        return res;
    }
};