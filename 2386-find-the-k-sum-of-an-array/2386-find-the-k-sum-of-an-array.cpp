class Solution {
    public:
    long long kSum(vector<int>& nums, int k) {
        sort(begin(nums), end(nums), [](int a, int b) { 
            return abs(a) < abs(b); 
        });

        long long res = accumulate(begin(nums), end(nums), 0LL, [](long long sum, int n) { 
            return sum + max(0, n); 
        });

        priority_queue<pair<long long, int>> pq;
        pq.push({res - abs(nums[0]), 0});

        while(--k) {
            auto [sum, i] = pq.top(); pq.pop();

            if (i + 1 < nums.size()) {
                pq.push({sum - abs(nums[i + 1]), i + 1});
                pq.push({sum + abs(nums[i]) - abs(nums[i + 1]), i + 1});
            }
            res = sum;
        }

        return res;
    }
};