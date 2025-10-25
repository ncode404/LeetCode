class Solution {
    public int totalMoney(int n) {
        int res=0, c=0;
        for(int i=0;i<n;i++) {
            if(i%7==0) c++;
            res+=(i%7+c);
        }
        return res;
    }
}