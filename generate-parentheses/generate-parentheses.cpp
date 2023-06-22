class Solution {
public:
    bool valid(string s) {
        int t=0;
        for(auto i:s) {
            if(i=='(') t++;
            else t--;
            if(t<0) return 0;
        }
        return t==0;
    }
    void add(int n,string s,vector<string> &ans) {
        if(n==0) {
            if(valid(s)) ans.push_back(s);
            return;
        }
        add(n-1,s+'(',ans);
        add(n-1,s+')',ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        add(2*n,"",ans);
        return ans;
    }
};