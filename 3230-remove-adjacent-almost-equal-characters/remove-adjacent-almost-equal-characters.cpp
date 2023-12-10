class Solution {
public:
    bool f(char c,char t) {
        if(c==t) return 1;
        if(t-1 == c || c-1 == t) return 1;
        return 0;
    }
    int removeAlmostEqualCharacters(string word) {
        int res=0;
        for(int i=1;i<word.size();i++) {
            if(f(word[i-1], word[i])) {
                word[i]='@'; res++;
            }
        }
        return res;
    }
};