class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m,p;
        for(auto i:arr) m[i]++;
        for(auto i:m) {
            p[i.second]++;
            if(p[i.second]==2) return 0;
        }
        return 1;
    }
};