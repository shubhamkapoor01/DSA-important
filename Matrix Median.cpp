#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll count(vector<vector<int>> &arr, int x) {
    ll cnt = 0;
    ll n = arr.size();
    ll m = arr[0].size() - 1;
    
    for (ll i = 0; i < n; i ++) {
        ll l = 0;
        ll r = m;
        
        while (l <= r) {
            ll mid = r + (l - r) / 2;
            
            if (arr[i][mid] <= x) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        cnt += l;
    }

    return cnt;
}

int Solution::findMedian(vector<vector<int>> &arr) {

    ll l = 0;
    ll r = 1e9;
    ll n = arr.size();
    ll m = arr[0].size();

    while(l <= r) {
        ll mid = r + (l - r) / 2;
        ll req = n * m / 2;
        ll cnt = count(arr, mid);

        if (cnt <= req) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return l;
}
