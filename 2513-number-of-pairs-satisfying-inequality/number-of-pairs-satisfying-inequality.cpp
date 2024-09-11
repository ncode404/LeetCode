class Solution {
    long long res=0;
    void merge(vector<int> &x,int l,int m,int r,int d) {
        int p=m-l+1, q=r-m;
        vector<int> t1(p), t2(q);
        for(int i=0;i<p;i++) t1[i]=x[l+i];
        for(int i=0;i<q;i++) t2[i]=x[m+1+i];

        for(auto i:t2) {
            res+=(upper_bound(t1.begin(), t1.end(), i+d)-t1.begin());
        }

        int i=0,j=0,k=l;
        while(i<p && j<q) {
            if(t1[i]<=t2[j]) x[k++]=t1[i++];
            else x[k++]=t2[j++];
        }
        while(i<p) x[k++]=t1[i++];
        while(j<q) x[k++]=t2[j++];
    }
    void mergeSort(vector<int> &x,int l,int r,int d) {
        if(l<r) {
            int m=l+(r-l)/2;
            mergeSort(x,l,m,d);
            mergeSort(x,m+1,r,d);
            merge(x,l,m,r,d);
        }
    }
public:
    long long numberOfPairs(vector<int>& x, vector<int>& y, int diff) {
        for(int i=0;i<x.size();i++) {
            x[i]-=y[i];
        }
        res=0;
        mergeSort(x,0,x.size()-1,diff);
        return res;
    }
};