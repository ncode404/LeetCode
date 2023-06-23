class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int a=0,e=0,iy=0,o=0,u=0,i,ans=0;
        for(i=0;i<word.size();) {
            while(i<word.size() && word[i]=='a') a++,i++;
            while(i<word.size() && word[i]=='e') e++,i++;
            while(i<word.size() && word[i]=='i') iy++,i++;
            while(i<word.size() && word[i]=='o') o++,i++;
            while(i<word.size() && word[i]=='u') u++,i++;
            if(a && e && iy && o && u) 
                ans=max(ans,a+e+iy+o+u);
            a=e=iy=o=u=0;
        }
        return ans;
    }
};