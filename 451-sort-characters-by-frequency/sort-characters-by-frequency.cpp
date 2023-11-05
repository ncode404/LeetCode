class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m;
        for(auto i:s) m[i]++;
        sort(s.begin(), s.end(), [&](char a, char b){
            if(m[a]==m[b]) return a>b;
            return m[a]>m[b];
        });
        return s;
    }
};