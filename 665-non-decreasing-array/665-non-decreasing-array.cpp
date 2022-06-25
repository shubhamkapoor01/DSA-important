class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; i ++) {
            if (nums[i] < nums[i - 1]) {
                int prev = nums[i - 1];
                nums[i - 1] = nums[i];
                bool possible = true;
                for (int j = 1; j < n; j ++) {
                    if (nums[j] < nums[j - 1]) {
                        possible = false;
                        break;
                    }
                }
                if (possible) return true;
                possible = true;
                nums[i - 1] = prev;
                nums[i] = prev;
                for (int j = 1; j < n; j ++) {
                    if (nums[j] < nums[j - 1]) {
                        possible = false;
                        break;
                    }
                }
                if (possible) return true;
                return false;
            }
        }
        return true;
    }
};