class Solution {
private:
    bool possible(vector<int>& nums, int penalty, int maxOperations) {
        for (auto &num: nums) {
            maxOperations -= num / penalty;
            if (num % penalty) maxOperations --;
            maxOperations ++;
        }
        return maxOperations >= 0;
    }
    
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int r = *max_element(nums.begin(), nums.end());
        int minPenalty = r;
        int l = 1;
        
        while (l <= r) {
            int penalty = l + (r - l) / 2;
            if (possible(nums, penalty, maxOperations)) {
                minPenalty = penalty;
                r = penalty - 1;
            } else {
                l = penalty + 1;
            }
        }
        
        return minPenalty;
    }
};