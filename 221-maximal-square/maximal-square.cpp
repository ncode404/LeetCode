class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size(), m=matrix[0].size(), i,j, res=0;
        vector<vector<int>> dp(n, vector<int> (m,0));

        for(i=n-1;i>=0;i--) {
            if(matrix[i][m-1]=='1') {
                dp[i][m-1]=1; res=1;
            }
        }
        for(i=m-1;i>=0;i--) {
            if(matrix[n-1][i]=='1') {
                dp[n-1][i]=1; res=1;
            }
        }

        for(i=n-2;i>=0;i--) {
            for(j=m-2;j>=0;j--) {
                if(matrix[i][j]=='1') {
                    dp[i][j]=min({dp[i+1][j], dp[i][j+1], dp[i+1][j+1]})+1;
                }
                res=max(res,dp[i][j]);
            }
        }
        return res*res;
    }
};