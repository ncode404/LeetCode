class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[](vector<int> &a,vector<int> &b){
            return a[1]<b[1];
        });
        int ans=1,i,j=0;
        for(i=1;i<pairs.size();i++) {
            if(pairs[i][0]>pairs[j][1])
            {ans++; j=i;}
        }
        return ans;
    }
};