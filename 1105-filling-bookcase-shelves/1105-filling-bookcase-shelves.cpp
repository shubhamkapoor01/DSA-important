class Solution {
private:
    int dp[1001][1001];
    
public:
    Solution() {
        memset(dp, -1, sizeof(dp));
    }
    
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth, int i = 0, int w = 0, int h = 0) {
        if (i >= books.size()) {
            return h;
        }
        
        if (dp[i][w] != -1) {
            return dp[i][w];
        }
        
        dp[i][w] = h + minHeightShelves(books, shelfWidth, i + 1, books[i][0], books[i][1]);
        
        if (w + books[i][0] <= shelfWidth) {
            dp[i][w] = min(dp[i][w], minHeightShelves(books, shelfWidth, i + 1, books[i][0] + w, max(h, books[i][1])));
        }
        
        return dp[i][w];
    }
};