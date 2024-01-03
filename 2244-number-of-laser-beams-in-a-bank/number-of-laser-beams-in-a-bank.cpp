class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int res = 0, t = -1;
        for(auto i:bank) {
            int c = 0;
            for(auto j:i) if(j=='1') c++;
            if(!c) continue;

            if(t != -1) res += (t*c);
            t = c;
        }
        return res;
    }
};