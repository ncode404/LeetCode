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
    string res;
    void dfs(TreeNode *root,string ans) {
        if(!root) return;
        if(root->left==NULL && root->right==NULL) {
            string t=ans;
            t+=char(root->val+'a');
            reverse(t.begin(),t.end());
            if(res=="") res=t;
            else res=min(res,t);
            return;
        }
        dfs(root->left,ans+char(root->val+'a'));
        dfs(root->right,ans+char(root->val+'a'));
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        res="";
        dfs(root,"");
        return res;
    }
};