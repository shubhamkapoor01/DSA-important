struct JOB {
    int profit;
    int start;
    int end;
};

class Solution {
private:
    int findNonConflicting(vector<JOB>& jobs, int start) {
        int r = jobs.size();
        int l = 0;
        
        while (l <= r) {
            int m = l + (r - l) / 2;
            
            if (jobs[m].end <= start) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        
        return l - 1;
    }
    
public:
    static bool compare(JOB& x, JOB& y) {
        if (x.end < y.end) {
            return true;
        } else if (x.end > y.end) {
            return false;
        } else {
            return x.start < y.start;
        }
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<JOB> jobs; 
        
        for (int i = 0; i < n; i ++) {
            JOB job;
            job.profit = profit[i];
            job.start = startTime[i];
            job.end = endTime[i];
            jobs.push_back(job);
        }
        
        sort(jobs.begin(), jobs.end(), compare);
        
        vector<int> dp(n, 0);
        dp[0] = jobs[0].profit;
        
        for (int i = 1; i < n; i ++) {
            int latestNonConflicting = findNonConflicting(jobs, jobs[i].start);
            dp[i] = max(dp[i - 1], jobs[i].profit + (latestNonConflicting >= 0 ? dp[latestNonConflicting] : 0));
        }
        
        return dp[n - 1];
    }
};