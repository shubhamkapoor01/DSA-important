class Solution {
private:
    int merge(vector<int>& nums, int sl, int el, int sr, int er, vector<int>& temp) {
        int count = 0;
        int i = sl;
        int j = sr;
        int k = sl;
        
        int l = sl;
        int r = sr;
        
        while (l <= el && r <= er) {
            if ((long)nums[l] > (long)2 * (long)nums[r]) {
                count += el - l + 1;
                r ++;
                
            } else {
                l ++;
            }
        }
        
        while (i <= el && j <= er) {
            if (nums[i] <= nums[j]) {
                temp[k] = nums[i];
                k ++;
                i ++;
                
            } else {
                temp[k] = nums[j];
                k ++;
                j ++;
            }
        }
        
        while (i <= el) {
            temp[k] = nums[i];
            k ++;
            i ++;
        }
        
        while (j <= er) {
            temp[k] = nums[j];
            k ++;
            j ++;
        }
        
        for (int idx = sl; idx <= er; idx ++) {
            nums[idx] = temp[idx];
        }
        
        return count;
    }
    
    int solve(vector<int>& nums, int l, int r, vector<int>& temp) {
        if (l >= r) return 0;
        int m = l + (r - l) / 2;
        int count = 0;
        count += solve(nums, l, m, temp);
        count += solve(nums, m + 1, r, temp);
        count += merge(nums, l, m, m + 1, r, temp);
        return count;
    }
    
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n);
        int ans = solve(nums, 0, n - 1, temp);
        // for (auto i: nums) {
        //     cout << i << " ";
        // }
        // cout << endl;
        return ans;
    }
};