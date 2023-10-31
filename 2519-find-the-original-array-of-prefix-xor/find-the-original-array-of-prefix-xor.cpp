class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int c=pref[0];
        for(int i=1;i<pref.size();i++) {
            int t = c^pref[i];
            pref[i] = t;
            c^=t;
        }
        return pref;
    }
};