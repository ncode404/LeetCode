class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        queue<vector<int>> q;
        q.push({e[0],e[1],0});
        vector<vector<int>> d={{0,1},{1,0},{-1,0},{0,-1}};
        while(!q.empty()) {
            int x=q.front()[0],cnt=q.front()[2];
            int y=q.front()[1];
            if(x==0||y==0||x==maze.size()-1||y==maze[0].size()-1) {
                if(x==e[0] && y==e[1]) {}
                else return cnt;
            }
            q.pop();
            for(auto i:d) {
                i[0]+=x; i[1]+=y;
                if(i[0]>=0 && i[1]>=0 && i[0]<maze.size() && i[1]<maze[0].size() && 
                            maze[i[0]][i[1]]=='.') {
                                maze[i[0]][i[1]]='+';
                                q.push({i[0],i[1],cnt+1});
                            }
            }
        }
        return -1;
    }
};