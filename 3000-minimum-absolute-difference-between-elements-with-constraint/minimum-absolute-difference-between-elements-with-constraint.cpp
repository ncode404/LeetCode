class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        map<int,int> m;
        for(int i=x;i<nums.size();i++) m[nums[i]]++;
        int res=INT_MAX,y=x;
        for(int i=0;i<nums.size()-x;i++) {
            auto lb=m.lower_bound(nums[i]);
            
            if(lb!=m.begin()) res=min(res,abs(nums[i]-prev(lb)->first));
            res=min(res,abs(nums[i]-lb->first));
            
            m[nums[i+x]]--;
            if(!m[nums[i+x]]) m.erase(nums[i+x]);
        }
        return res;
    }
};