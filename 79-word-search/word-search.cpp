class Solution {
    int n,m,temp;
    void dfs(int i, int j,vector<vector<char>>& board,string word,int k,vector<vector<int>> &vis) {
        if(k==word.size()) {
            temp=1; return;
        }
        if(i+1<n && word[k]==board[i+1][j] && vis[i+1][j]==-1) {
            vis[i+1][j]=0;
            dfs(i+1,j,board,word,k+1,vis);
            vis[i+1][j]=-1;
        }
        if(i>=1 && word[k]==board[i-1][j] && vis[i-1][j]==-1) {
            vis[i-1][j]=0;
            dfs(i-1,j,board,word,k+1,vis);
            vis[i-1][j]=-1;
        }
        if(j+1<m && word[k]==board[i][j+1] && vis[i][j+1]==-1) {
            vis[i][j+1]=0;
            dfs(i,j+1,board,word,k+1,vis);
            vis[i][j+1]=-1;
        }
        if(j>=1 && word[k]==board[i][j-1] && vis[i][j-1]==-1) {
            vis[i][j-1]=0;
            dfs(i,j-1,board,word,k+1,vis);
            vis[i][j-1]=-1;
        }
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size(), m=board[0].size();
        temp=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(board[i][j]==word[0]) {
                    vector<vector<int>> vis(n,vector<int> (m,-1));
                    vis[i][j]=0;
                    if(word.size()==1) return 1;
                    else dfs(i,j,board,word,1,vis); // start at i,j

                    if(temp==1) return 1;
                }
            }
        }
        return 0;
    }
};