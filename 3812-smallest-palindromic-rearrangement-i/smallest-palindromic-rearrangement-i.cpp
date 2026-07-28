class Solution {
public:
    string smallestPalindrome(string s) {
        unordered_map<char,int> m;
        for(auto i:s) m[i]++;
        string ss="",ts="";
        char odd='@';
        for(char i='a';i<='z';i++) {
            int cnt=m[i]/2;
            while(cnt--) ss+=i, ts+=i;

            if(m[i]%2) {
                odd=i;
            }
        }
        reverse(ts.begin(),ts.end());
        if(odd!='@') ss+=odd; 
        ss+=ts;
        return ss;
    }
};