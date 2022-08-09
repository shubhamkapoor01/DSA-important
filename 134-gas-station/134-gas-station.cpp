class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int currGas = 0;
        int start = 0;
        
        if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0)) {
            return -1;
        }
        
        for (int i = 0; i < n; i ++) {
            currGas += gas[i] - cost[i];
            if (currGas < 0) {
                currGas = 0;
                start = i + 1;
            }
        }
        
        return start;
    }
};