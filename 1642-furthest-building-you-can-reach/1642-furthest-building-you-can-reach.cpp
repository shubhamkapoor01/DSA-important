class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = heights.size();
        
        if (!ladders) {
            for (int i = 1; i < n; i ++) {
                bricks -= max(0, heights[i] - heights[i - 1]);
                if (bricks < 0) {
                    return i - 1;
                }
            }
            return n - 1;
        }
        
        for (int i = 1; i < n; i ++) {
            if (heights[i] <= heights[i - 1]) {
                continue;
            }
            
            if (pq.size() < ladders) {
                pq.push(heights[i] - heights[i - 1]);
                continue;
            }
            
            int kth = pq.top();
            
            if (kth >= heights[i] - heights[i - 1]) {
                bricks -= heights[i] - heights[i - 1];
                if (bricks < 0) {
                    return i - 1;
                }
                
            } else {
                pq.pop();
                pq.push(heights[i] - heights[i - 1]);
                bricks -= kth;
                if (bricks < 0) {
                    return i - 1;
                }
            }
        }
        
        return n - 1;
    }
};