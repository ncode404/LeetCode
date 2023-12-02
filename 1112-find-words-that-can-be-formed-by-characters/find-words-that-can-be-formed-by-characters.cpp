class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> mChars;
        for(auto i:chars) mChars[i]++;
        int res=0;
        for(auto i:words) {
            unordered_map<char,int> mI;
            for(auto j:i) mI[j]++;
            bool b=0;
            for(char c='a'; c<='z'; c++) {
                if(mChars[c]<mI[c]) {
                    b=1; break;
                }
            }
            if(!b) res += i.size();
        }
        return res;
    }
};