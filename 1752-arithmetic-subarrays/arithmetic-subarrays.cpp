class Solution {
public:
    bool check(vector<int> t) {
        for(int i=1; i<t.size(); i++) {
            if((t[i]-t[i-1]) != (t[1]-t[0]))
            return 0;
        }
        return 1;
    }

    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        vector<bool> res(l.size(), 0);
        for(int i=0; i<l.size(); i++) {
            vector<int> t;
            for(int j=l[i]; j<=r[i]; j++) {
                t.push_back(nums[j]);
            }
            sort(t.begin(), t.end());
            if(check(t)) res[i]=1;
        }
        return res;

    }
};