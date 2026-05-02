#include <iostream>
using namespace std;
const int MOD = 1000000007;
int n, x;
int coins[101];
int dp[1000001];
int solve(int sum) {
    if (sum == 0) return 1;
    if (sum < 0) return 0;
    if (dp[sum] != -1) return dp[sum];
    int ways = 0;
    for (int i = 0; i < n; i++) {
        ways = (ways + solve(sum - coins[i])) % MOD;
    }
    return dp[sum] = ways;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    for (int i = 0; i <= x; i++) dp[i] = -1;
    cout << solve(x) << endl;
    return 0;
}
