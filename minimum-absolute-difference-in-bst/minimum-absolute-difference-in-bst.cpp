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
        nodeVals.push_back(root->val);
        dfs(root->left,nodeVals);
        dfs(root->right,nodeVals);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> nodeVals;
        dfs(root,nodeVals);
        int ans=INT_MAX;
        for(int i=0;i<nodeVals.size();i++) {
            for(int j=i+1;j<nodeVals.size();j++)
                ans=min(ans,abs(nodeVals[j]-nodeVals[i]));
        }
        return ans;
    }
};