class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,bool> m;
        for(auto i:nums) {
            if(m.find(i)==m.end()) m[i]=0;
            else m[i]=1;
        }
        int c=0;
        for(auto i:m) if(i.second==0) c++;
        return c!=nums.size();
    }
};