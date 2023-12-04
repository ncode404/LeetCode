class Solution {
public:
    string largestGoodInteger(string num) {
        string ans="";
        int res=-1;
        for(int i=1; i<num.size()-1; i++) {
            if(num[i-1]==num[i] && num[i+1]==num[i]) {
                int x=(num[i]-'0')*100+(num[i]-'0')*10+(num[i]-'0');
                if(x>res) {
                    res=x; ans=num.substr(i-1,3);
                }
            }
        }
        return ans;
    }
};