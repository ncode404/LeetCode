class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto i:nums) m[i]++;
        int mn=0;
        for(auto i:m) {
            if(i.second==1) return -1;
            if(i.second%3==0) mn+=i.second/3;
            else if(i.second%3==1) mn+=(2+(i.second-4)/3);
            else mn+=(1+(i.second-2)/3);
        }
        return mn;
    }
};