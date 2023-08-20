class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int res=0;
        for(auto i:nums) {
            if(m[k+i]) res+=m[i+k];
            if(m[i-k]) res+=m[i-k];
            m[i]++;
        }
        return res;
    }
};