class Solution {
private:
    int partition(vector<int>& nums, int left, int right) {
        int n = nums.size();
        int pivot = nums[right];
        int i = left;
        int j = left;
        while (i < right) {
            if (nums[i] > pivot) {
                i ++;
            } else {
                swap(nums[i], nums[j]);
                i ++;
                j ++;
            }
        }
        swap(nums[j], nums[i]);
        return j;
    }
    
    int kthMax(vector<int>& nums, int l, int r, int k) {
        int idx = partition(nums, l, r);
        if (idx < k) return kthMax(nums, idx + 1, r, k);
        if (idx > k) return kthMax(nums, l, idx - 1, k);
        else return nums[k];
    }
    
public:
    int findKthLargest(vector<int>& nums, int k) {
        return kthMax(nums, 0, nums.size() - 1, nums.size() - k);
    }
};