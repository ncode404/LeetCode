class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> Q;
        unordered_map<string,bool> m;
        for(auto i:wordList) m[i]=1;
        m[beginWord] = 0;
        Q.push({beginWord, 1});
        while (!Q.empty()) {
            string node = Q.front().first;
            int lvl = Q.front().second;
            Q.pop();
            if(node == endWord) {
                return lvl;
            }
            for(int i=0; i<wordList[0].size(); i++) {
                char original = node[i];
                for(char c='a'; c<='z'; c++) {
                    node[i] = c;
                    if(m[node]) {
                        Q.push({node, lvl+1});
                        m[node] = 0;
                    }
                }
                node[i] = original;
            }
        }
        return 0;
    }
};