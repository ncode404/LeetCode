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
    void dfs(TreeNode *root,vector<int> &nodeVals) {
        if(!root) return;
        dfs(root->left,nodeVals);
        nodeVals.push_back(root->val);
        dfs(root->right,nodeVals);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> nodeVals;
        dfs(root,nodeVals);
        int ans=INT_MAX;
        for(int i=1;i<nodeVals.size();i++) {
            ans=min(ans,nodeVals[i]-nodeVals[i-1]);
        }
        return ans;
    }
};