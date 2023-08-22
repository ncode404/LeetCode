class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> m;
        vector<int> ans;
        int res=0;
        for(int i=0;i<A.size();i++) {
            if(!m[A[i]]) m[A[i]]++; 
            else res++;
            if(!m[B[i]]) m[B[i]]++;
            else res++;
            ans.push_back(res);
        }
        return ans;
    }
};