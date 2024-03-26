class Node {
    public:
    Node *links[26];
    int c=0;
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
            if(node->links[i-'a']==NULL) {
                Node *newNode = new Node();
                node->links[i-'a']=newNode;
                node=node->links[i-'a'];
                node->c++;
            }
            else {
                node=node->links[i-'a'];
                node->c++;
            }
        }
    }
    int match(string &s) {
        Node *node=root;
        int res=0;
        for(auto i:s) {
            if(node->links[i-'a']==NULL) break;
            node=node->links[i-'a'];
            res+=node->c;
        }
        return res;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        for(auto i:words) {
            insert(i);
        }
        vector<int> res;
        for(auto i:words) {
            res.push_back(match(i));
        }
        return res;
    }
};