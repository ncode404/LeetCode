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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root); q.push(NULL);
        int level=0,ans=INT_MIN,s=root->val,res=0,tempSum=0;
        while(!q.empty()) {
            auto t=q.front(); q.pop();
            if(t) {
                if(t->left) {
                    q.push(t->left);
                    tempSum+=t->left->val;
                }
                if(t->right) {
                    q.push(t->right);
                    tempSum+=t->right->val;
                }
            }
            else {
                level++;
                if(s>ans) {ans=s; res=level;}
                if(q.size()) q.push(NULL);
                s=tempSum; tempSum=0;
            }
        }
        return res;
    }
};