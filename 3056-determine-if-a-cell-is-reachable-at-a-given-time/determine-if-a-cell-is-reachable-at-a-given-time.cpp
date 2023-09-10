class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        return (sx==fx && fy==sy && t==1)?0:max(abs(sx-fx),abs(sy-fy))<=t;
    }
};