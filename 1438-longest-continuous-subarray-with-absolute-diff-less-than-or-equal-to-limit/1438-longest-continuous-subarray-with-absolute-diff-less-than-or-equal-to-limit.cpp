class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        deque<int> minq;
        deque<int> maxq;
        int ans = 0;
        int we = 0;
        int ws = 0;
        
        while (we < n) {
            while (!minq.empty() && nums[minq.back()] >= nums[we]) minq.pop_back();
            while (!maxq.empty() && nums[maxq.back()] <= nums[we]) maxq.pop_back();
            
            minq.push_back(we);
            maxq.push_back(we);
            
            while (nums[maxq.front()] - nums[minq.front()] > limit) {
                if (minq.front() < maxq.front()) {
                    ws = minq.front() + 1;
                    minq.pop_front();
                } else {
                    ws = maxq.front() + 1;
                    maxq.pop_front();
                }
            }
            
            ans = max(ans, we - ws + 1);
            we ++;
        }
        
        return ans;
    }
};