class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int curr = 0;
        int next = 0;
        
        while (next < n) {
            nums[curr] = nums[next];
            
            while (next < n && nums[curr] == nums[next]) {
                next ++;
            }
            curr ++;
        }
        
        return curr;
    }
};
