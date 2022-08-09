class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalCost = 0;
        int totalGas = 0;
        int currGas = 0;
        int start = 0;
        
        for (int i = 0; i < n; i ++) {
            currGas += gas[i] - cost[i];
            
            if (currGas < 0) {
                currGas = 0;
                start = i + 1;
            }
            
            totalCost += cost[i];
            totalGas += gas[i];
        }
        
        return totalGas < totalCost ? -1 : start;
    }
};