class Solution {
public:
    vector<int> twoSum(vector<int>& a, int t) {
        unordered_map<int,int> m;
        for(int i=0;i<a.size();i++) {
            if(m[t-a[i]]) return {m[t-a[i]]-1,i};
            m[a[i]]=i+1;
        }
        return {};
    }
};