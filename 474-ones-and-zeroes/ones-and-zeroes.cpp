class Solution {
    vector<vector<vector<int>>> dp;
    int f(int m,int n,int i,vector<int> &ones,vector<int> &zeros) {
        if(i==ones.size()) return 0;
        if(dp[i][m][n]!=-1) return dp[i][m][n];
        int res=0;
        if(n>=ones[i] && m>=zeros[i]) res=max(res, 1+f(m-zeros[i],n-ones[i],i+1,ones,zeros));
        res=max(res,f(m,n,i+1,ones,zeros));
        return dp[i][m][n] = res;
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<int> ones,zeros;
        for(auto i:strs) {
            int c1=0,c2=0;
            for(auto j:i) 
                if(j=='0') c1++; else c2++;
            ones.push_back(c2);
            zeros.push_back(c1);
        }
        dp.resize(strs.size()+1,vector<vector<int>> (m+1, vector<int> (n+1,-1)));
        return f(m,n,0,ones,zeros);
    }
};