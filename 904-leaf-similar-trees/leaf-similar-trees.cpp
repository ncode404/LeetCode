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
    vector<int> x,y;
    void f(TreeNode *r, bool b) {
        if(!r) return;
        if(!r->left && !r->right) {
            if(!b) x.push_back(r->val);
            else y.push_back(r->val);
        }
        f(r->left,b);
        f(r->right,b);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        f(root1,0); f(root2,1);
        return x==y;
    }
};