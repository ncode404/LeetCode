class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_map<int,int> m;
        for(auto i:nums) m[i]++;
        unordered_set<int> v;
        for(auto i:nums) {
            if(!m[i-1]) v.insert(i);
        }
        int res=0;
        for(auto i:v) {
            int t=i,c=0;
            while(m[t]) {
                c++; t++;
            }
            res=max(res,c);
        }
        return res;
    }
};