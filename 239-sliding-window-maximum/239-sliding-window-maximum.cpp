class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;
        int we = 0;
        int ws = 0;
        while (we < n) {
            while (!dq.empty() && nums[dq.back()] <= nums[we]) {
                dq.pop_back();
            }
            dq.push_back(we);
            while (!dq.empty() && we - dq.front() + 1 > k) {
                ws = dq.front() + 1;
                dq.pop_front();
            }
            if (we >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
            we ++;
        }
        return ans;
    }
};