class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int f[26]={[0 ... 25]=INT_MAX}, l[26], res=0;
        for(int i=0;i<s.size();i++) {
            f[s[i]-'a']=min(f[s[i]-'a'],i);
            l[s[i]-'a']=i;
        }
        for(int i=0;i<26;i++) {
            if(f[i]<l[i]) 
            res+=unordered_set<char>(s.begin()+f[i]+1,s.begin()+l[i]).size();
        }
        return res;
    }
};