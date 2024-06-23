/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    vector<int> res;
    void f(Node *root) {
        if(!root) return;
        res.push_back(root->val);
        for(auto i:root->children) {
            f(i);
        }
    }
public:
    vector<int> preorder(Node* root) {
        f(root);
        return res;
    }
};