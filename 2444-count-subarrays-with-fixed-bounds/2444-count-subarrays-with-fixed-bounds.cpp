#define ll long long

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        ll n = nums.size();
        ll invalid = -1;
        ll minIdx = -1;
        ll maxIdx = -1;
        ll answer = 0;
        
        for (ll i = 0; i < n; i ++) {
            if (nums[i] == minK) minIdx = i;
            if (nums[i] == maxK) maxIdx = i;
            if (nums[i] < minK || nums[i] > maxK) invalid = i;
            answer += max(0LL, min(minIdx, maxIdx) - invalid);         
        }
        
        return answer;
    }
};