class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [] (vector<int>& a, vector<int>& b) {
            return a[1] > b[1];
        });
        
        int cnt = 0;
        
        for (int i = 0; i < boxTypes.size(); i ++) {
            if (truckSize > boxTypes[i][0]) {
                cnt += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            } else {
                cnt += truckSize * boxTypes[i][1];
                truckSize = 0;
                break;
            }
        }
        
        return cnt;
    }
};