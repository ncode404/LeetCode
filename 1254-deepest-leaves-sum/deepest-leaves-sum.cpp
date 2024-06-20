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
    int res=0;
    int findHeight(TreeNode *root) {
        if(!root) return 0;
        return 1+max(findHeight(root->left), findHeight(root->right));
    }
    void f(TreeNode *root,int x,int &h) {
        if(!root) return;
        if(x==h) res+=root->val;

        f(root->left,x+1,h);
        f(root->right,x+1,h);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        int h = findHeight(root);
        f(root,1,h);
        return res;
    }
};