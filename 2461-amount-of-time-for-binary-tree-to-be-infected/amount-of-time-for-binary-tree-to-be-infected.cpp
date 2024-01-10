/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void convertToGraph(unordered_map<int, vector<int>> &G, TreeNode* r) {
        if(!r) return;
        if(r->left) {
            G[r->val].push_back(r->left->val);
            G[r->left->val].push_back(r->val);
        }
        if(r->right) {
            G[r->val].push_back(r->right->val);
            G[r->right->val].push_back(r->val);
        }
        convertToGraph(G,r->left);
        convertToGraph(G,r->right);
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> G;
        convertToGraph(G,root);
        // BFS -> {node, cost}
        queue<pair<int,int>> Q;
        Q.push({start,0});
        unordered_set<int> s;
        s.insert(start);
        int res=0;
        while(!Q.empty()) {
            auto it=Q.front();
            Q.pop();
            int node=it.first, cost=it.second;
            res=cost;
            for(auto adjNode:G[node]) {
                if(s.find(adjNode)==s.end()) {
                    s.insert(adjNode);
                    Q.push({adjNode, cost+1});
                }
            }
        }
        return res;
    }
};