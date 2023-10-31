class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<int,int> m1,m2;
        for(auto i:p) m1[i]++;

        int k=p.size();
        for(int i=0;i<k;i++) m2[s[i]]++;
        vector<int> v;
        if(m1==m2) v.push_back(0);

        for(int i=k;i<s.size();i++) {
            m2[s[i-k]]--;
            if(!m2[s[i-k]]) m2.erase(s[i-k]);
            m2[s[i]]++;
            if(m1==m2) v.push_back(i-k+1);
        }
        return v;
    }
};