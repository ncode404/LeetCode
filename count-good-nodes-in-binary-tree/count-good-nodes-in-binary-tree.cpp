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
public:
    int goodNodes(TreeNode* root) {
        int ans=1;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()) {
            int i,size=q.size();
            for(i=0;i<size;i++) {
                auto t=q.front(); q.pop();
                if(t->left) {
                    q.push(t->left);
                    if(t->left->val >= t->val) ans++;
                    else t->left->val = t->val;
                }
                if(t->right) {
                    q.push(t->right);
                    if(t->right->val >= t->val) ans++;
                    else t->right->val = t->val;
                }
            }
        }
        return ans;
    }
};