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
    void dfs(int t,TreeNode *root,vector<vector<int>> &res,vector<int> temp) {
        if(!root) return;
        if(!root->left && !root->right) {
            t-=root->val; temp.push_back(root->val);
            if(!t) res.push_back(temp);
            return;
        }
        temp.push_back(root->val);
        dfs(t-root->val,root->left,res,temp);
        dfs(t-root->val,root->right,res,temp);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int t) {
        vector<vector<int>> res;
        vector<int> temp;
        dfs(t,root,res,temp);
        return res;
    }
};