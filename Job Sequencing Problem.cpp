class Solution {
    public:
    static bool compare(Job x, Job y) {
        return x.profit > y.profit;
    }
    
    vector<int> JobScheduling(Job arr[], int n) { 
        sort(arr, arr + n, compare);
        vector<int> ans(101, -1);
        
        int currTime = 0;
        int numJobs = 0;
        int maxProfit = 0;
        
        for (int i = 0; i < n; i ++) {
            if (ans[arr[i].dead] == -1) {
                ans[arr[i].dead] = arr[i].profit;
            } else {
                for (int j = arr[i].dead - 1; j >= 1; j --) {
                    if (ans[j] == -1) {
                        ans[j] = arr[i].profit;
                        break;
                    }
                }
            }
        }
        
        for (int i = 0; i < ans.size(); i ++) {
            if (ans[i] != -1) {
                maxProfit += ans[i];
                numJobs ++;
            }
        }
        
        return {numJobs, maxProfit};
    } 
};
