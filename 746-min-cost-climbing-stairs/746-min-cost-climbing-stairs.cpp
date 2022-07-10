class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prevprev = 0;
        int prev = cost[0];
        for (int i = 1; i < cost.size(); i ++) {
            int curr = min(prevprev, prev) + cost[i];
            prevprev = prev;
            prev = curr;
        }
        return min(prev, prevprev);
    }
};