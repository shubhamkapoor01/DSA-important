class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1 = -1e9;
        int ele2 = -1e9;
        int cnt1 = 0;
        int cnt2 = 0;
        
        for (int i = 0; i < nums.size(); i ++) {
            if (ele1 == nums[i]) {
                cnt1 ++;
            } else if (ele2 == nums[i]) {
                cnt2 ++;
            } else if (cnt1 == 0) {
                cnt1 ++;
                ele1 = nums[i];
            } else if (cnt2 == 0) {
                cnt2 ++;
                ele2 = nums[i];
            } else {
                cnt1 --;
                cnt2 --;
            }
        }
        
        cnt1 = 0;
        cnt2 = 0;
        
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] == ele1) {
                cnt1 ++;
            } else if (nums[i] == ele2) {
                cnt2 ++;
            }
        }
        
        if (cnt1 <= nums.size() / 3) {
            ele1 = -1e9;
        }
        
        if (cnt2 <= nums.size() / 3) {
            ele2 = -1e9;
        }
        
        if (ele1 == ele2) {
            if (ele1 == -1e9 && ele2 == -1e9) {
                return {};
            } else {
                return {ele1};
            }
        } else {
            if (ele1 == -1e9) {
                return {ele2};
            } else if (ele2 == -1e9) {
                return {ele1};
            } else {
                return {ele1, ele2};
            }
        }
    }
};
