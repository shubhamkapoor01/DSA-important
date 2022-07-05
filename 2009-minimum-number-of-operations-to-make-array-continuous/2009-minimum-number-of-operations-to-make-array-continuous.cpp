class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int we = 0;
        int ws = 0;
        int answer = 1e9;
        map<int, int> mp;
        
        while (we < n) {
            mp[nums[we]] ++;
            
            while (mp.rbegin() -> first - mp.begin() -> first >= n) {
                mp[nums[ws]] --;
                
                if (!mp[nums[ws]]) {
                    mp.erase(nums[ws]);
                }
                
                ws ++;
            }
            
            answer = min(answer, n - (int)mp.size());
            we ++;
        }
        
        return answer;
    }
};