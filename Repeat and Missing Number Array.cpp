#define ll long long

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    ll sum = 0;
    ll sumsq = 0;
    ll n = A.size();

    for (ll i = 0; i < n; i ++) {
        sum += (ll)A[i];
        sumsq += (ll)A[i] * (ll)A[i];
    }

    ll actual = n * (n + 1) / 2;
    ll actualsq = n * (n + 1) * (2 * n + 1) / 6;

    ll mPlusR = (actualsq - sumsq) / (actual - sum);
    ll mMinusR = actual - sum;

    ll missing = (mPlusR + mMinusR) / 2;
    ll repeated = missing - mMinusR;

    return {repeated, missing};
}
