class Solution {
public:
    long long countCommas(long long n) {
        string s=to_string(n);
        if(n==1000000000000000) {
            return (n-999999999999)*4+(999999999999-999999999)*3+(999999999-999999)*2+999999-999+1;
        }
        if(s.size()<=3) return 0;
        else if(s.size()<=6) return n-1000+1;
        else if(s.size()<=9) {
            return (n-999999)*2+999999-999;
        }
        else if(s.size()<=12) {
            return (n-999999999)*3+(999999999-999999)*2+999999-999;
        }
        return (n-999999999999)*4+(999999999999-999999999)*3+(999999999-999999)*2+999999-999;
    }
};