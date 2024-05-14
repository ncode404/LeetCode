class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto i:nums) m[i]++;
        for(int i=1;i<=100000;i++) {
            if(!m[i]) return i;
        }
        return 100001;
    }
};