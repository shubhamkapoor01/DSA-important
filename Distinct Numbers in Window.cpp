vector<int> Solution::dNums(vector<int> &nums, int k) {
    int n = nums.size();
    unordered_map<int, int> mp;
    int ws = 0;
    int we = 0;
    vector<int> ans;
    while (we < n) {
        mp[nums[we]] ++;

        if (we - ws + 1 > k) {
            mp[nums[ws]] --;
            if (mp[nums[ws]] == 0) {
                mp.erase(nums[ws]);
            }
            ws ++;
        }

        if (we - ws + 1 == k) {
            ans.push_back(mp.size());
        }

        we ++;
    }
    return ans;
}
