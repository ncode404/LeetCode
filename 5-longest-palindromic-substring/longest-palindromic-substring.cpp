class Solution {
public:
    string longestPalindrome(string s) {
        int ans=1, ini=0;
        for(int i=0;i<s.size();i++) {
            int j=i-1, k=i+1, cnt=1;
            // odd length expand from i
            while(j>=0 && k<s.size() && s[j]==s[k]) cnt+=2, j--, k++;
            if(cnt>ans) ans=cnt, ini=j+1;

            if(i+1<s.size() && s[i]==s[i+1]) {
                // if(2>ans) ans=2, ini=i;

                int j=i-1, k=i+2, cnt=2;
                // even length expand from i,i+1
                while(j>=0 && k<s.size() && s[j]==s[k]) cnt+=2, j--, k++;
                if(cnt>ans) ans=cnt, ini=j+1;
            }
        }
        // ini=max(ini,0);
        return s.substr(ini, ans);
    }
};