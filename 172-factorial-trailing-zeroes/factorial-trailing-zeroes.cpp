class Solution {
public:
    int trailingZeroes(int n) {
        int i=5,c=0;
        while(n>=i) {
            c+=n/i;
            i*=5;
        }
        return c;
    }
};