/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    #define pb push_back
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // convert into graph
        queue<TreeNode*> q;
        q.push(root);
        unordered_map<int,vector<int>> m;
        while(!q.empty()) {
            int i,size=q.size();
            for(i=0;i<size;i++) {
                auto t=q.front(); q.pop();
                if(t->left) {
                    m[t->val].pb(t->left->val);
                    m[t->left->val].pb(t->val);
                    q.push(t->left);
                }
                if(t->right) {
                    m[t->val].pb(t->right->val);
                    m[t->right->val].pb(t->val);
                    q.push(t->right);
                }
            }
        }

        // bfs for distance k
        queue<pair<int,int>> p;
        p.push({target->val,0});
        vector<int> ans,vis(501,0);
        vis[target->val]=1;
        while(!p.empty()) {
            auto t=p.front(); p.pop();
            if(t.second==k) ans.pb(t.first);
            for(auto i:m[t.first]) {
                if(!vis[i]) {
                    vis[i]=1;
                    p.push({i,t.second+1});
                }
            }
        }
        return ans;
    }
};