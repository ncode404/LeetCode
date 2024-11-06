class Solution {
public:
    string compressedString(string word) {
        char c=word[0];
        string res;
        int cnt=0;
        for(auto i:word) {
            if(c==i && cnt<9) cnt++;
            else {
                res+=cnt+'0'; res+=c;
                c=i; cnt=1;
            }
        }
        res+=cnt+'0'; res+=c;
        return res;
    }
};