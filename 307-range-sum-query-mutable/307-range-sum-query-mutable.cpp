class NumArray {
private:
    vector<int> tree;
    int size;
    
    void build(int start, int end, int treeidx, vector<int>& nums) {
        if (start == end) {
            tree[treeidx] = nums[start];
            return;
        }
        int mid = start + (end - start) / 2;
        build(start, mid, 2 * treeidx, nums);
        build(mid + 1, end, 2 * treeidx + 1, nums);
        tree[treeidx] = tree[2 * treeidx] + tree[2 * treeidx + 1];
        return;
    }
    
    void updateTree(int index, int val, int start, int end, int treeidx) {
        if (start == end) {
            tree[treeidx] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (index <= mid) {
            updateTree(index, val, start, mid, 2 * treeidx);
        } else {
            updateTree(index, val, mid + 1, end, 2 * treeidx + 1);
        }
        tree[treeidx] = tree[2 * treeidx] + tree[2 * treeidx + 1];
        return;
    }
    
    int sumRangeTree(int left, int right, int start, int end, int treeidx) {
        if (start > right || end < left) {
            return 0;
        }
        if (start >= left && end <= right) {
            return tree[treeidx];
        }
        int mid = start + (end - start) / 2;
        int leftSum = sumRangeTree(left, right, start, mid, 2 * treeidx);
        int rightSum = sumRangeTree(left, right, mid + 1, end, 2 * treeidx + 1);
        return leftSum + rightSum;
    }
    
public:
    NumArray(vector<int>& nums) {
        size = nums.size();
        tree = vector<int> (4 * size, 0);
        build(0, size - 1, 1, nums);
    }
    
    void update(int index, int val) {
        updateTree(index, val, 0, size - 1, 1);
    }
    
    int sumRange(int left, int right) {
        return sumRangeTree(left, right, 0, size - 1, 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */