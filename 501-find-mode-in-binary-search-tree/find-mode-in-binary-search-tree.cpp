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
    int res;
    unordered_map<int,int> m;
    void f(TreeNode *r) {
        if(!r) return;
        f(r->left);
        m[r->val]++;
        res = max(res,m[r->val]);
        f(r->right);
    }
    vector<int> findMode(TreeNode* root) {
        res=0; f(root);
        vector<int> ans;
        for(auto i:m) {
            if(i.second == res)
            ans.push_back(i.first);
        }
        return ans;
    }
};