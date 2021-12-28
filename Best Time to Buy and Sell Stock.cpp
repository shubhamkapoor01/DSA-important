class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int curr = 0;
        int answer = 0;
        
        for (int i = 0; i < prices.size(); i ++) {
            buy = min(buy, prices[i]);
            curr = prices[i] - buy;
            answer = max(answer, curr);
        }
        
        return answer;
    }
};
