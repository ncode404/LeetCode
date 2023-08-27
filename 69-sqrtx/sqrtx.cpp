class Solution {
public:
    int mySqrt(int x) {
        long long l=0, h=INT_MAX, ans=0;
        while(l<=h) {
            long long m=(h-l)/2+l;
            if(m*m>=x) {
                ans=m; h=m-1;
            }
            else l=m+1;
        }
        return (ans*ans==x)?ans:ans-1;
    }
};