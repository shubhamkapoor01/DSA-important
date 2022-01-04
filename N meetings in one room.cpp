class Solution {
    public:
    static bool compare(pair<int, int> x, pair<int, int> y) {
        if (x.second < y.second) {
            return true;
        } else if (y.second < x.second) {
            return false;
        } else {
            return x.first < y.first;
        }
    }
    
    int maxMeetings(int start[], int end[], int n) {
        vector<pair<int, int>> meeting(n);
        for (int i = 0; i < n; i ++) {
            meeting[i].first = start[i];
            meeting[i].second = end[i];
        }
        
        sort(meeting.begin(), meeting.end(), compare);
        
        int maxMeet = 0;
        int currEnd = -1;
        
        for (int i = 0; i < n; i ++) {
            if (currEnd >= meeting[i].first) {
                continue;
            }
            
            currEnd = meeting[i].second;
            maxMeet ++;
        }
        
        return maxMeet;
    }
};
