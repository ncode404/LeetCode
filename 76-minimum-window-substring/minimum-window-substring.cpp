class Solution {
public:
    bool check(unordered_map<char,int> &tmap,unordered_map<char,int> &smap) {
        for(auto i:tmap)
            if(smap[i.first]<i.second) return 0;
        return 1;
    }
    string minWindow(string s, string t) {
        unordered_map<char,int> smap,tmap;
        for(auto i:t) tmap[i]++;
        int l=-1,r=-1,j=0,i,p=INT_MAX;
        for(i=0;i<s.size();i++) {
            smap[s[i]]++;
            while(j<=i && check(tmap,smap)) {
                if(i-j<p) {
                    p=i-j;
                    l=j; r=i;
                }
                smap[s[j]]--; j++;
            }
        }
        string ans;
        if(l==-1 or r==-1) return ans;
        for(i=l;i<=r;i++) ans+=s[i];
        return ans;
    }
};