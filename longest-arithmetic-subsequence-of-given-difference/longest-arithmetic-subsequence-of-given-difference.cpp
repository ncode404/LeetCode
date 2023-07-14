class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> m;
        for(int i=arr.size()-1;i>=0;i--) {
            m[arr[i]] = m[arr[i]+difference]+1;
        }
        int ans=1;
        for(auto i:m) ans=max(ans,i.second);
        return ans; 
    }
};