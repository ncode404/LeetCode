class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long res=0, t=INT_MIN;
        vector<long long> pre;
        for(auto i:nums) {
            t=max(t,(long long)i);
            pre.push_back(__gcd(t,(long long)i));
        }
        sort(pre.begin(),pre.end());
        for(int i=0;i<pre.size()/2;i++) res+=(__gcd(pre[i], pre[pre.size()-i-1]));
        return res;
    }
};