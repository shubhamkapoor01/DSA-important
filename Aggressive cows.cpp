#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define endl "\n"


bool possible(vector<ll> v, ll m, ll c) {
	ll n = v.size();
	ll prev = v[0];
	c --;

	for (ll i = 1; i < n; i ++) {
		if (v[i] - prev >= m) {
			prev = v[i];
			c --;
		}

		if (c == 0) {
			return true;
		}

	}

	return false;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll tc;
	cin >> tc;
	while (tc --) {

		ll n, c;
		cin >> n >> c;
		vector<ll> v(n);
		for (ll i = 0; i < n; i ++)
			cin >> v[i];

		sort(v.begin(), v.end());

		ll ans;
		ll l = 1;
		ll r = v[v.size() - 1];

		while (l <= r) {
			ll m = l + (r - l) / 2;

			if (possible(v, m, c)) {
				ans = m;
				l = m + 1;
			} else {
				r = m - 1;
			}
		}

		cout << ans << endl;
	}
	return 0;
}
