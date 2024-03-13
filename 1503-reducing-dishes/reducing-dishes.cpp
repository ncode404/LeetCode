class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        sort(s.begin(),s.end());
        int j=1,res=0,ss=0;
        for(auto i:s) {
            if(i>=0) {
                res+=(i*j);
                ss+=i;
                j++;
            }
        }
        reverse(s.begin(),s.end());
        for(auto i:s) {
            if(i<0) {
                res=max(res,res+ss+i);
                ss+=i;
            }
        } 
        return res;
    }
};