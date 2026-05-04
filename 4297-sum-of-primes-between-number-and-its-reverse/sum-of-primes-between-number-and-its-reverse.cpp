class Solution {
    int prime(int n) {
        if(n<=1) return 0;
        if(n==2||n==3) return 1;
        if(n%2==0||n%3==0) return 0;
        for(int i=5;i*i<=n;i+=6) {
            if(n%i==0 || n%(i+2)==0) return 0;
        }
        return 1;
    }
public:
    int sumOfPrimesInRange(int n) {
        string p=to_string(n);
        reverse(p.begin(),p.end());
        int x=stoi(p), res=0;
        for(int i=min(x,n);i<=max(x,n);i++) {
            if(prime(i)) res+=i;
        }
        return res;
    }
};