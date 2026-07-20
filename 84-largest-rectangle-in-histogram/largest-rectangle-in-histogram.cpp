class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // solution is we need to find where does NSE, PSE lies in array
        // NextSmallestElement, PreviousSmallestElement

        // we can use stack for finding both. ans=max(ans,a[i]*(nse-pse-1))
        stack<int> s;
        int res=0;
        for(int i=0;i<heights.size();i++) {
            while(!s.empty() && heights[s.top()]>heights[i]) {
                // pulling elements from top to bottom and we know 
                // pse = prev ele in stack. nse is current element
                int element=s.top(); s.pop();
                int nse=i, pse=(s.empty()?-1:s.top());
                res=max(res,heights[element]*(nse-pse-1));
            }
            s.push(i);
        }
        while(!s.empty()) {
            int element=s.top(); s.pop(); // we wont have nse. so N
            int nse=heights.size(), pse=(s.empty()?-1:s.top());
            res=max(res,heights[element]*(nse-pse-1));
        }
        return res;
    }
};