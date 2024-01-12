class Solution {
public:
    bool vowel(char c) {
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
    }
    bool halvesAreAlike(string s) {
        int c1=0,c2=0;
        for(int i=0;i<s.size();i++) {
            if(vowel(s[i])) {
                if(i<s.size()/2) c1++;
                else c2++;
            }
        }
        return c1==c2;
    }
};