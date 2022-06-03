class Solution {
private:
    int checkElement(vector<int>& nums, int l, int r, int target) {
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) {
                return m;
            }
            
            if (nums[m] < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return -1;
    }
    
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int r = n - 1;
        int l = 0;
        
        while (l <= r) {
            int m = l + (r - l) / 2;
            
            if (m < n - 1 && nums[m] > nums[m + 1]) {
                int left = checkElement(nums, 0, m, target);
                int right = checkElement(nums, m + 1, n - 1, target);
                
                if (left >= 0) return left;
                if (right >= 0) return right;
                break;
            }
            
            if (nums[m] < nums[r]) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        
        int idx = checkElement(nums, 0, n - 1, target);
        return idx >= 0 ? idx : -1;
    }
};