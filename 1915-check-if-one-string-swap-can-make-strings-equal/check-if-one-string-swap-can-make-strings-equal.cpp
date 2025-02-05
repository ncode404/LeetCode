class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int c=0;
        vector<char> vc;
        for(int i=0;i<s1.size();i++) {
            if(s1[i]!=s2[i]) {
                c++;
                vc.push_back(s1[i]);
                vc.push_back(s2[i]);
                if(c>2) return 0;
            }
        }
        if(c==1 || c==2 && (vc[1]!=vc[2] || vc[0]!=vc[3])) return 0;
        return 1;
    }
};