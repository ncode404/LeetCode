class Solution {
public:
    void f(int n,int k,int i,vector<vector<int>> &ans,vector<int> &temp) {
        if(i==n+1) {
            if(temp.size()==k) ans.push_back(temp);
            return;
        }
        if(temp.size()>k) return;
        temp.push_back(i);
        f(n,k,i+1,ans,temp); //pick
        temp.pop_back();
        f(n,k,i+1,ans,temp); //notpick
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        f(n,k,1,ans,temp);
        return ans;
    }
};