class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;
        deque<int> dq;
        int we = 0;
        int ws = 0;
        
        while (we < n) {
            while (!dq.empty() && nums[dq.back()] <= nums[we]) {
                dq.pop_back();
            }
            
            dq.push_back(we);
            
            while (!dq.empty() && we - ws + 1 > k) {
                if (dq.front() == ws) {
                    dq.pop_front();
                }
                ws ++;
            }
            
            if (we - ws + 1 == k) {
                result.push_back(nums[dq.front()]);
            }
            
            we ++;
        }
        
        return result;
    }
};