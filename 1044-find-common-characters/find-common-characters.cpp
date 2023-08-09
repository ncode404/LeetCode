class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<int,unordered_map<char,int>> m;
        for(int i=0;i<words.size();i++) {
            unordered_map<char,int> p;
            for(auto j:words[i]) p[j]++;
            m[i]=p;
        }
        vector<string> res;
        for(char c='a';c<='z';c++) {
            int ans=INT_MAX; 
            string s; s+=c;
            for(auto i:m) ans=min(ans,m[i.first][c]);
            if(ans!=INT_MAX) 
            while(ans--) res.push_back(s);
        }
        return res;
    }
};