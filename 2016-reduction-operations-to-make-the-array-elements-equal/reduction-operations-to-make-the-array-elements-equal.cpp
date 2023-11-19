class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int res=0, c=0;
        map<int,int> m;
        for(auto i:nums) m[i]++;
        for(auto i:m) {
            res += (c*i.second);
            c++;
        }
        return res;
    }
};