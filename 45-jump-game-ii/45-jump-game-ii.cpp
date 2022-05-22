class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        int l = 0;
        int r = 0;
        while (r < n - 1) {
            int range = 0;
            for (int i = l; i <= r; i ++) {
                range = max(range, i + nums[i]);
            }
            l = r + 1;
            r = range;
            jumps ++;
        }
        return jumps;
    }
};

