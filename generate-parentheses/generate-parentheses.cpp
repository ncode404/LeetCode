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
    bool check(string s,int n) {
        int leftcount=0,rightcount=0;
        for(auto i:s) {
            if(i=='(') leftcount++;
            else rightcount++;
        }
        return (leftcount>n/2||rightcount>n/2);
    }
    void add(int n,string s,vector<string> &ans,int size) {
        if(n==0) {
            if(valid(s)) ans.push_back(s);
            return;
        }
        if(check(s,size)) return;
        add(n-1,s+'(',ans,size);
        add(n-1,s+')',ans,size);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        add(2*n,"",ans,2*n);
        return ans;
    }
};