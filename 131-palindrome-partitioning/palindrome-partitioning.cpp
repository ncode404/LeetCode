class Solution {
    vector<vector<string>> res;
    vector<string> t;
    int valid(string &s,int i,int j) {
        while(i<=j)
            if(s[i++]!=s[j--]) return 0;
        return 1;
    }
    void f(string &s,int i) {
        if(i==s.size()) {
            res.push_back(t);
            return;
        }
        for(int j=i;j<s.size();j++) {
            if(valid(s,i,j)) {
                t.push_back(s.substr(i,j-i+1));
                f(s,j+1);
                t.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        f(s,0);
        return res;
    }
};