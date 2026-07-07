class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0) return 0; // runtime error
        long long res=0;
        string s=to_string(n), t;
        for(auto i:s) {
            if(i!='0') t+=i;
            res+=(i-'0');
        }
        return res*stoll(t);
    }
};