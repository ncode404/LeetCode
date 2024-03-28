class NumArray {
public:
    vector<int> seg;
    int n;

    NumArray(vector<int>& nums) {
        int n=nums.size();
        this->n=n;
        seg.resize(4*n,0);
        create(nums,0,0,n-1);
    }

    void create(vector<int> &nums,int i,int l,int r) {
        if(l==r) {
            seg[i]=nums[l];
            return;
        }
        int m=(l+r)/2;
        create(nums,2*i+1,l,m);
        create(nums,2*i+2,m+1,r);
        seg[i]=seg[2*i+1]+seg[2*i+2];
    }

    void upd(int ind,int val,int i,int l,int r) {
        if(l==r) {
            seg[i]=val;
            return;
        }
        int m=(l+r)/2;
        if(ind<=m) upd(ind,val,2*i+1,l,m);
        else upd(ind,val,2*i+2,m+1,r);
        seg[i]=seg[2*i+1]+seg[2*i+2];
    }

    int get(int left,int right,int i,int l,int r) {
        if(l>=left && r<=right) return seg[i];
        if(r<left || l>right) return 0;
        int m=(l+r)/2;
        return get(left,right,2*i+1,l,m)+get(left,right,2*i+2,m+1,r);
    }
    
    void update(int index, int val) {
        upd(index,val,0,0,n-1);
    }
    
    int sumRange(int left, int right) {
        return get(left,right,0,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */