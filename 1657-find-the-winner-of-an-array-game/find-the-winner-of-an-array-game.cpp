class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if(k>arr.size())
        return *max_element(arr.begin(), arr.end());
        deque<int> d;
        for(auto i:arr) d.push_back(i);
        unordered_map<int,int> m;
        while(1) {
            int x=d.front(); d.pop_front();
            int y=d.front(); d.pop_front();
            if(x>y) {
                d.push_front(x);
                d.push_back(y);
                m[x]++;
                if(m[x]==k) return x;
            }
            else {
                d.push_front(y);
                d.push_back(x);
                m[y]++;
                if(m[y]==k) return y;
            }
        }
    }
};