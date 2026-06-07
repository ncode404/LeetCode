class Solution {
    public int[] twoSum(int[] nums, int target) {
        int temp[] = new int[2];
        HashMap<Integer, Integer> hmap = new HashMap<Integer, Integer>();
        for(int i=0;i<nums.length;i++) {
            hmap.put(nums[i], i);
        }
        for(int i=0;i<nums.length;i++) {
            if(hmap.containsKey(target-nums[i])) {
                temp[0]=i; temp[1]=hmap.get(target-nums[i]);
                if(temp[0]!=temp[1]) return temp;
            }
        }
        return temp;

    }
}