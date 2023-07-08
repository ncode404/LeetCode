const string s[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

class Solution {
public:
    void f(string &digits,vector<string> &ans,int i,string &temp) {
        if(i==digits.size()) {
            ans.push_back(temp);
            return;
        }
        for(int j=0;j<s[digits[i]-'0'].size();j++) {
            temp+=s[digits[i]-'0'][j];
            f(digits,ans,i+1,temp);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()) return ans;
        string temp;
        f(digits,ans,0,temp);
        return ans;
    }
};