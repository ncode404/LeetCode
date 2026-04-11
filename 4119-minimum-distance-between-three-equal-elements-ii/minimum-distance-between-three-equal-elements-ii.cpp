class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>> m;
        for(int i=0;i<nums.size();i++) {
            m[nums[i]].push_back(i);
        }
        int res=INT_MAX,x,y,z;
        for(auto i:m) {
            if(i.second.size()>=3) {
                for(int j=2;j<i.second.size();j++) {
                    int t=abs(i.second[j-2]-i.second[j])+abs(i.second[j-1]-i.second[j])+abs(i.second[j-1]-i.second[j-2]);
                    if(t<res) res=t;
                }
            }
        }
        if(res==INT_MAX) return -1; 
        return res;
    }
};