class Solution {
    int f(vector<int> &a,vector<int> &b,int i,int j,vector<vector<int>> &dp) {
        if(i==a.size()||j==b.size()) return 0;
        if(dp[i][j]!=3001) return dp[i][j];

        int res=INT_MIN;
        res=max({a[i]*b[j]+f(a,b,i+1,j+1,dp), f(a,b,i+1,j,dp), f(a,b,i,j+1,dp)});
        return dp[i][j] = res;
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size()+1, vector<int> (nums2.size()+1,3001));
        int res = f(nums1,nums2,0,0,dp);
        if(res) return res;

        // negative summation
        int a = *max_element(nums1.begin(), nums1.end());
        int b = *min_element(nums1.begin(), nums1.end());
           
        int c = *max_element(nums2.begin(), nums2.end());
        int d = *min_element(nums2.begin(), nums2.end());
        return max(a*d, b*c);
    }
};