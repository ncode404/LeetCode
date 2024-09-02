class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        vector<int> res;
        multiset<int> s;
        for(auto i:queries) {
            s.insert(abs(i[0])+abs(i[1]));
            if(s.size()>k) s.erase(s.find(*s.rbegin()));
            if(s.size()==k) res.push_back(*s.rbegin());
            else res.push_back(-1);
        }
        return res;
    }
};