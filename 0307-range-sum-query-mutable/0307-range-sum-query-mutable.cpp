class NumArray {
    vector<int> sums;
    void insert(vector<int>& nums, int s, int l, int r) {
        if(l==r) {
            sums[s] = nums[l];
        } else {
            int m = l + (r-l)/2;
            insert(nums, 2*s, l, m);
            insert(nums, 2*s+1, m+1, r);
            sums[s] = sums[2*s] + sums[2*s+1];
        }
    }
    void update(int s, int l, int r, int idx, int val) {
        if(l==r) {
            sums[s] = val;
        } else {
            int m = l + (r-l)/2;
            if(idx <= m) {
                update(2*s, l, m, idx, val);
            } else {
                update(2*s+1, m+1, r, idx, val);
            }
            sums[s] = sums[2*s] + sums[2*s+1];
        }
    }
    int sum(int s, int l, int r, int sl, int sr) {
        if(l==r) {
            return sums[s];
        } else {
            if(l == sl && r == sr) {
                return sums[s];
            }
            int m = l + (r-l)/2;
            if(m >= sr) {
                return sum(2*s, l, m, sl, sr);
            } else if(m < sl) {
                return sum(2*s+1, m+1, r, sl, sr);
            }
            return sum(2*s, l, m, sl, m) + sum(2*s+1, m+1, r, m+1, sr);
        }
    }
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        sums.resize(4*n);
        insert(nums, 1, 0, n-1);
    }
    
    void update(int index, int val) {
        update(1, 0, sums.size()/4 - 1, index, val);
    }
    
    int sumRange(int left, int right) {
        return sum(1, 0, sums.size()/4 - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */