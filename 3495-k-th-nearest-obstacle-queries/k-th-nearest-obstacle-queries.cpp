class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        vector<int> res;
        priority_queue<int> pq;
        for(auto i:queries) {
            pq.push(abs(i[0])+abs(i[1]));
            if(pq.size()>k) pq.pop();
            if(pq.size()==k) res.push_back(pq.top());
            else res.push_back(-1);
        }
        return res;
    }
};