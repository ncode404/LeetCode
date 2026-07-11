class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i=0;i<numbers.size();i++) {
            int low=i+1,high=numbers.size()-1;
            while(low<=high) {
                int mid=low+(high-low)/2;
                if(numbers[mid]==target-numbers[i]) {
                    return {i+1,mid+1};
                }
                if(numbers[mid]>target-numbers[i]) high=mid-1;
                else low=mid+1;
            }
        }
        return {};
    }
};