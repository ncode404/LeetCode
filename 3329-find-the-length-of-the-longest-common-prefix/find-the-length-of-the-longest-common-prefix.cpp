class Node {
    public:
    Node *links[10];
    bool eow=false;
};
class Solution {
public:
    Node *root;
    Solution() {
        root=new Node();
    }
    void insert(string &s) {
        Node *node=root;
        for(auto i:s) {
            if(node->links[i-'0']==NULL) {
                Node *newNode = new Node();
                node->links[i-'0']=newNode;
                node=node->links[i-'0'];
            }
            else {
                node=node->links[i-'0'];
            }
        }
        node->eow=true;
    }
    int match(string &s) {
        Node *node=root;
        int c=0;
        for(auto i:s) {
            if(node->links[i-'0'] ==NULL) break;
            node=node->links[i-'0']; c++;
        }
        return c;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        for(auto i:arr1) {
            string t=to_string(i);
            insert(t);
        }
        int res=0;
        for(auto i:arr2) {
            string t=to_string(i);
            res=max(res,match(t));
        }
        return res;
    }
};