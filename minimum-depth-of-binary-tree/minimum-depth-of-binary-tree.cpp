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
    int minDepth(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        if(!root) return 0;
        int level=1;
        while(!q.empty()) {
            int i,size = q.size();
            for(i=0;i<size;i++) {
                auto t = q.front();
                q.pop();
                if(!t->left && !t->right)
                return level;
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            level++;
        }
        return 0;
    }
};