class Solution {
    public:
    static bool compare(Item x, Item y) {
        return ((double)x.value / (double)x.weight) > ((double)y.value / (double)y.weight);
    }
    
    double fractionalKnapsack(int W, Item arr[], int n) {
        sort(arr, arr + n, compare);
        
        double maxVal = 0;
        for (int i = 0; i < n; i ++) {
            if (arr[i].weight <= W) {
                maxVal += arr[i].value;
                W -= arr[i].weight;
            } else {
                maxVal += (double)arr[i].value * (double)W / (double)arr[i].weight;
                W = 0;
                break;
            }
        }
        
        return maxVal;
    }
};
