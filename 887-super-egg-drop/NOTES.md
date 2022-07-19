dp[M][K]means that, given K eggs and M moves,
what is the maximum number of floor that we can check.
​
The dp equation is:
dp[m][k] = dp[m - 1][k - 1] + dp[m - 1][k] + 1,
which means we take 1 move to a floor,
if egg breaks, then we can check dp[m - 1][k - 1] floors.
if egg doesn't breaks, then we can check dp[m - 1][k] floors.
​
dp[m][k] is the number of combinations and it increase exponentially to N
​
Complexity
For time, O(NK) decalre the space, O(KlogN) running,
For space, O(NK).