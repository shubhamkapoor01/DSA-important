class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int currSatisfied = 0;
        int maxSatisfied = 0;
        int windowStart = 0;
        int windowEnd = 0;
        int startIdx = 0;
        int endIdx = 0;
        
        while (windowEnd < n) {
            if (grumpy[windowEnd]) {
                currSatisfied += customers[windowEnd];
            }
            
            if (windowEnd - windowStart + 1 > minutes) {
                if (grumpy[windowStart]) {
                    currSatisfied -= customers[windowStart];
                }
                windowStart ++;
            }
            
            if (currSatisfied > maxSatisfied) {
                maxSatisfied = currSatisfied;
                startIdx = windowStart;
                endIdx = windowEnd;
            }
            
            windowEnd ++;
        }
        
        int totalSatisfied = 0;
        
        for (int i = 0; i < n; i ++) {
            if (i >= startIdx && i <= endIdx) {
                totalSatisfied += customers[i];
                
            } else {
                totalSatisfied += (1 - grumpy[i]) * customers[i];
            }
        }
        
        return totalSatisfied;
    }
};