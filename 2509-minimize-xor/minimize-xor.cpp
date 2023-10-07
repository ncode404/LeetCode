class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int k=__builtin_popcount(num2),cnt=0;
        string s;
        for(int i=31;i>=0;i--) {
            int p=(num1>>i);
            p&=1;
            if(p) s+='1', cnt++;
            else s+='0';
        }
        if(cnt==k) return num1;
        if(cnt>k) {
            string t;
            for(int i=0;i<=31;i++) {
                if(s[i]=='1') {
                    if(k) t+='1',k--;
                    else t+='0';
                }
                else t+='0';
            }
            int res=0;
            for(auto i:t) {
                res*=2;
                if(i=='1') res++;
            }
            return res;
        }

        k-=cnt;
        for(int i=31;i>=0;i--) {
            if(!k) break;
            if(s[i]=='0') s[i]='1',k--;
        }

        int res=0;
            for(auto i:s) {
                res*=2;
                if(i=='1') res++;
            }
            return res;
    }
};