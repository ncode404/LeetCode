class Solution {
    int checkLeft(vector<int> &arr, int i) {
        int c=0;
        while(i>=0 && arr[i]!=-1) {
            i--; c++;
        }
        return c;
    }
    int checkRight(vector<int> &arr, int i) {
        int c=0;
        while(i<arr.size() && arr[i]!=-1) {
            i++; c++;
        }
        return c;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        map<int,queue<int>> m;
        for(int i=0;i<arr.size();i++) {
            m[arr[i]].push(i);
        }
        long long res=0, mod=1e9+7;
        for(auto i:m) {
            while(!m[i.first].empty()) {
                int val = m[i.first].front();
                int t1 = checkLeft(arr, val-1);
                int t2 = checkRight(arr, val+1);
                res = (res+(i.first*(((t1+1)*(t2+1))%mod))%mod)%mod;
                arr[m[i.first].front()]=-1;
                m[i.first].pop();
            }
        }
        return res;
    }
};