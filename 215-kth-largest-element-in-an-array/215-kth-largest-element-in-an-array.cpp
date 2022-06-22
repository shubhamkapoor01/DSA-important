class Solution {
private:
    int partition(vector<int>& nums, int left, int right) {
        int n = nums.size();
        int i = left;
        int j = left;
        while (j < right) {
            if (nums[j] > nums[right]) {
                j ++;
            } else {
                swap(nums[i], nums[j]);
                i ++;
                j ++;
            }
        }
        swap(nums[i], nums[j]);
        return i;
    }
    
    int kthMax(vector<int>& nums, int l, int r, int k) {
        int idx = partition(nums, l, r);
        if (idx > k) return kthMax(nums, l, idx - 1, k);
        if (idx < k) return kthMax(nums, idx + 1, r, k);
        return nums[idx];
    }
    
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return kthMax(nums, 0, n - 1, n - k);
    }
};