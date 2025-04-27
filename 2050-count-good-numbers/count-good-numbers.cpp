#define mod 1000000007
class Solution {
    long long pp(long long a,long long b) {
        if(b==0) return 1;
        if(b==1) return a;
        if(b%2==0) {
            return pp((a*a)%mod,b/2)%mod;
        }
        return (a*pp(a,b-1)%mod)%mod;
    }
public:
    int countGoodNumbers(long long n) {
        long long res=pp(4,n/2)*pp(5,n/2+n%2);
        return res%mod;
    }
};