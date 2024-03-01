class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int one=0,zero=0;
        for(auto i:s) {
            if(i=='1') one++;
            else zero++;
        }
        s.clear();
        for(int i=0;i<one-1;i++) s+='1';
        for(int i=0;i<zero;i++) s+='0';
        return s+='1';
    }
};