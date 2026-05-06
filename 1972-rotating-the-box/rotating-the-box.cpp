class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& grid) {
        vector<vector<char>> res, temp;
        for(auto i:grid) {
            int c=0;
            vector<char> t(i.size());
            for(int j=0;j<i.size();j++) {
                if(i[j]=='*') {
                    for(int k=j-1;k>=0;k--) {
                        if(c<=0) break;
                        t[k]='#'; c--;
                    }
                    t[j]='*';
                }
                else t[j]='.';

                if(i[j]=='#') c++;
            }
            if(c>0) {
                for(int k=i.size()-1;k>=0;k--) {
                        if(c<=0) break;
                        t[k]='#'; c--;
                    }
            }
            res.push_back(t);
        }
        for(auto i:res) {
            for(auto j:i) cout<<j<<" ";
            cout<<"\n";
        }
        stack<vector<char>> s;
        for(int i=0;i<res.size();i++) {
            s.push(res[i]);
        }
        while(!s.empty()) {
            temp.push_back(s.top());
            s.pop();
        } 
        vector<vector<char>> ans(res[0].size(), vector<char> (res.size(),'\0'));
        for(int i=0;i<res.size();i++) {
            for(int j=0;j<res[0].size();j++) ans[j][i]=temp[i][j];
        }
        return ans;
    }
};