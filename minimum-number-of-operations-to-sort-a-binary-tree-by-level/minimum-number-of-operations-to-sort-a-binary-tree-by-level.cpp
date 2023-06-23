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
    int check_min(vector<int> temp,vector<int> res) {
        unordered_map<int,int> m;
        int cnt=0,i;
        for(i=0;i<temp.size();i++) {
            m[temp[i]] = i+1;
        }
        for(i=0;i<temp.size();i++) {
            if(temp[i]!=res[i]) {
                cnt++;
                swap(temp[i],temp[m[res[i]]-1]);
                m[temp[m[res[i]] - 1]] = m[res[i]];
            }
        }
        return cnt;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root); int ans=0;
        while(!q.empty()) {
            int i,size=q.size();
            vector<int> temp,res;
            for(i=0;i<size;i++) {
                TreeNode *t=q.front(); q.pop();
                temp.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            res=temp; sort(res.begin(),res.end());
            ans+=check_min(temp,res);
        }
        return ans;
    }
};