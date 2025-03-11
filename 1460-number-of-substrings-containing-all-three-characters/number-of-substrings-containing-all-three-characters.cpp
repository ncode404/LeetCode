class Solution {
public:
    int numberOfSubstrings(string s) {
        deque<int> a,b,c;
        for(int i=0;i<s.size();i++) {
            if(s[i]=='a') a.push_back(i);
            else if(s[i]=='b') b.push_back(i);
            else c.push_back(i);
        }
        int res=0, t=0;
        while(!a.empty() && !b.empty() && !c.empty()) {
            res+=s.size()-max({a.front(),b.front(),c.front()});;
            if(a.front()==t) a.pop_front();
            else if(b.front()==t) b.pop_front();
            else c.pop_front();
            t++;
        }
        return res;
    }
};