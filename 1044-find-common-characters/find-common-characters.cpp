class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char,int> m;
        for(auto i:words[0]) m[i]++;
        for(int i=1;i<words.size();i++) {
            unordered_map<char,int> p;
            for(auto j:words[i]) p[j]++;
            for(auto j:m) 
            m[j.first]=min(m[j.first],p[j.first]);
        }
        vector<string> res;
        for(auto i:m) {
            int t=i.second;
            string s; s+=i.first;
            while(t--) res.push_back(s);
        }
        return res;
    }
};