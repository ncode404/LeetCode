class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long s = 0;
        for(auto i:chalk) s+=i;
        k%=s;
        for(int i=0;i<chalk.size();i++) {
            if(chalk[i]>k) return i;
            k-=chalk[i];
        }
        return -1;
    }
};