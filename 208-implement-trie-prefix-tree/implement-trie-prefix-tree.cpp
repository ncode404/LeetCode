class Node {
    public:
    Node *links[26];
    bool eow=false;
};
class Trie {
    Node *root;
public:
    Trie() {   
        root=new Node();
    }
    
    void insert(string word) {
        Node *node=root;
        for(auto i:word) {
            if(node->links[i-'a']==NULL) {
                Node *nn = new Node();
                node->links[i-'a']=nn;
                node=node->links[i-'a'];
            }
            else {
                node=node->links[i-'a'];
            }
        }
        node->eow=true;
    }
    
    bool search(string word) {
        Node *node=root;
        for(auto i:word) {
            if(node->links[i-'a']==NULL) return 0;
            node=node->links[i-'a'];
        }
        return node!=NULL && node->eow;
    }
    
    bool startsWith(string prefix) {
        Node *node=root;
        for(auto i:prefix) {
            if(node->links[i-'a']==NULL) return 0;
            node=node->links[i-'a'];
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */