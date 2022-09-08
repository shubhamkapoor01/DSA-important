#define ll long long

class Solution {
private:
    set<pair<ll, ll>> busy;
    vector<ll> count;
    set<ll> free;
    
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        for (ll i = 0; i < n; i ++) {
            count.push_back(0);
            free.insert(i);
        }
        
        sort(meetings.begin(), meetings.end());
        
        for (ll i = 0; i < meetings.size(); i ++) {
            while (busy.size() && meetings[i][0] >= busy.begin() -> first) {
                free.insert(busy.begin() -> second);
                busy.erase(busy.begin());
            }
            
            if (free.size()) {
                busy.insert({meetings[i][1], *free.begin()});
                count[*free.begin()] ++;
                free.erase(free.begin());
                
            } else {
                busy.insert({busy.begin() -> first + (ll)meetings[i][1] - (ll)meetings[i][0], busy.begin() -> second});
                count[busy.begin() -> second] ++;
                busy.erase(busy.begin());
            }
        }
        
        ll room = -1;
        ll times = -1;
        
        for (ll i = 0; i < n; i ++) {
            if (times < count[i]) {
                times = count[i];
                room = i;
            }
        }
        
        return room;
    }
};