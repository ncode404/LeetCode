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
    int m[10]={0};
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        if(!root) return 0;
        m[root->val]++;
        if(!root->left && !root->right) {
            int odd=0;
            for(int i=1;i<=9;i++) if(m[i]&1) odd++;
            m[root->val]--;
            if(odd>1) return 0;
            return 1;
        }
        int leftCon = pseudoPalindromicPaths(root->left);
        int rightCon = pseudoPalindromicPaths(root->right);
        m[root->val]--;
        return leftCon+rightCon;
    }
};