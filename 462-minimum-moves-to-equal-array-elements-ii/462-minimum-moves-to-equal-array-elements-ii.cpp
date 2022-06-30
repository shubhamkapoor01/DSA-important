class Solution {
private:
    int partition(vector<int>& nums, int l, int r) {
        int i = l;
        int j = l;
        
        while (i < r) {
            if (nums[i] > nums[r]) {
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
        
    int getMedian(vector<int>& nums, int l, int r) {
        int pos = partition(nums, l, r);
        if (pos > nums.size() / 2) return getMedian(nums, l, pos - 1);
        if (pos < nums.size() / 2) return getMedian(nums, pos + 1, r);
        return nums[pos];
    }
    
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        
        int median = getMedian(nums, 0, n - 1);
        
        for (int i = 0; i < n; i ++) {
            cnt += abs(nums[i] - median);
        }
        
        return cnt;
    }
};