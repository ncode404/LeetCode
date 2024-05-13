class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;

        int res=9, cnt=0, t=10;
        for(int i=1;i<n;i++) {
            cnt += (res*(t-1));
            res = (res*(t-1));
            t--;
        }
        return cnt+10;
    }
};