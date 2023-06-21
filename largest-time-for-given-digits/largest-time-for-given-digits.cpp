class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int hour = arr[0]*10+arr[1],minute = arr[2]*10+arr[3];
        string ans="";
        if(hour<24 && minute<59) {
            if(hour<10) ans+='0';
            ans+=to_string(hour)+":";
            if(minute<10) ans+='0';
            ans+=to_string(minute);
        }
        while(next_permutation(arr.begin(),arr.end())) {
            hour = arr[0]*10+arr[1],minute = arr[2]*10+arr[3];
            if(hour<24 && minute<59) {
                string t;
                if(hour<10) t+='0';
                t+=to_string(hour)+":";
                if(minute<10) t+='0';
                t+=to_string(minute);
                ans=max(ans,t);
            }
        }
        return ans;
    }
};