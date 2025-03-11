class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res;
        int i=0,j=0,temp=0;
        while(i<word1.size() && j<word2.size()) {
            if(temp==0) res+=word1[i++], temp=1;
            else res+=word2[j++], temp=0;
        }
        while(i<word1.size()) res+=word1[i++];
        while(j<word2.size()) res+=word2[j++];
        return res;
    }
};