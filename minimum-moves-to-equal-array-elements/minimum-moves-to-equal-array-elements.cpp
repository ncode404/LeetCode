class Solution {
public:
    #define all(x) x.begin(),x.end()
    int minMoves(vector<int>& nums) {
        return accumulate(all(nums),0L)-(*min_element(all(nums))*nums.size());
    }
};