class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ele1 = -1;
        int ele2 = -1;
        int cnt1 = 0;
        int cnt2 = 0;
        for (auto &i: nums) {
            if (ele1 == i) {
                cnt1 ++;
            } else if (ele2 == i) {
                cnt2 ++;
            } else if (cnt1 == 0) {
                cnt1 = 1;
                ele1 = i;
            } else if (cnt2 == 0) {
                cnt2 = 1;
                ele2 = i;
            } else {
                cnt1 --;
                cnt2 --;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        for (auto &i: nums) {
            if (i == ele1) cnt1 ++;
            if (i == ele2) cnt2 ++;
        }
        vector<int> ans;
        if (ele1 == ele2 && cnt1 > n / 3) return {ele1};
        if (cnt1 > n / 3) ans.push_back({ele1});
        if (cnt2 > n / 3) ans.push_back({ele2});
        return ans;
    }
};