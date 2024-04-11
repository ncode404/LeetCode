class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        for(auto i:num) {
            while(!s.empty() && s.top()>i && k-->0) 
                s.pop();
            s.push(i);
        }
        while(!s.empty() && k-->0) s.pop();
        string res;
        while(!s.empty()) {
            res+=s.top(); s.pop();
        }
        while(!res.empty() && res.back()=='0') 
            res.pop_back();
        reverse(res.begin(),res.end());
        if(res.empty()) return "0";
        return res;
    }
};