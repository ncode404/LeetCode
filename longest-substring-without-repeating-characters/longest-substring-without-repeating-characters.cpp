class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int x=0,ans=0,i;
        for(i=0;i<s.size();i++) {
            if(m[s[i]]) {
                x=max(x,m[s[i]]); 
                m[s[i]]=0;
            }
            m[s[i]]=i+1;
            ans=max(ans,i-x+1);
        }
        return ans;
    }
};