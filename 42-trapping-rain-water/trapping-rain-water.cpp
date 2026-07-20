class Solution {
public:
    int trap(vector<int>& height) {
        int maxi=*max_element(height.begin(),height.end()), cnt=0; 
        // max element and how many times it repeated
        
        for(auto i:height) {
            if(i==maxi) cnt++;
        }
        int t=0, res=0, p=cnt;
        for(int i=0;i<height.size();i++) {
            t=max(t,height[i]);
            if(height[i]==maxi) {
                if(p<=1) break;  // after last max it is overflows.
                p--;
            }
            res+=t-height[i];
        }
        t=0; p=cnt;
        for(int i=height.size()-1;i>=0;i--) {
            t=max(t,height[i]);
            if(t==maxi) break;
            res+=t-height[i];
        }
        return res;
    }
};