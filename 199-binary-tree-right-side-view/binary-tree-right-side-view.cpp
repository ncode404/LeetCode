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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root); q.push(NULL);
        vector<int> res;
        int prev=-1;
        while(!q.empty()) {
            auto it=q.front();
            q.pop();
            if(it!=NULL) {
                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
                prev=it->val;
            }
            else {
                res.push_back(prev);
                if(q.size()) q.push(NULL);
            }
        }
        return res;
    }
};