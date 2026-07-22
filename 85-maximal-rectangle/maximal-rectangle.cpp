class Solution {
    int n,m;
    vector<vector<int>> chk, chk2;
    void create(vector<vector<char>>& matrix) {
        for(int i=0;i<n;i++) {
            vector<int> temp;
            int cnt=0;
            for(auto j:matrix[i]) {
                if(j=='1') cnt++;
                else cnt=0;
                temp.push_back(cnt);
            }
            chk[i]=temp;
        }
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        //take this reference 
        //https://leetcode.com/problems/largest-rectangle-in-histogram/
        //now instead of one row from prev que, we need to check every row and every column
        n=matrix.size(), m=matrix[0].size();
        chk.resize(n); chk2.resize(m,vector<int> (n,0));
        create(matrix);
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                chk2[j][i]=chk[i][j];
            }
        }
        int res=0;
        for(auto i:chk2) {
            stack<int> s; // storing indices
            for(int j=0;j<n;j++) {
                while(!s.empty() && i[s.top()]>i[j]) {
                    int ele=s.top(); s.pop();
                    int nse=j, pse=(s.empty()?-1:s.top());
                    res=max(res,i[ele]*(nse-pse-1));
                }
                s.push(j);
            }
            while(!s.empty()) {
                int ele=s.top(); s.pop();
                int nse=n, pse=(s.empty()?-1:s.top());
                res=max(res,i[ele]*(nse-pse-1));
            }
        }
        return res;
    }
};