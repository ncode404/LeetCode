class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // {-1,0,1} => {notVisited, blue, red}


        vector<int> color(graph.size(), -1);
        for(int t=0; t<graph.size(); t++) {
            if(color[t]==-1) {
                queue<int> Q;
                Q.push(t); color[t]=0;
                while(!Q.empty()) {
                    int node = Q.front();
                    Q.pop();
                    for(auto i:graph[node]) {
                        if(color[i]==-1) {
                            Q.push(i);
                            color[i]=color[node]^1;
                        }
                        else {
                            if(color[i]==color[node])
                            return 0;
                        }
                    }
                }
            }
        }
        return 1;
    }
};