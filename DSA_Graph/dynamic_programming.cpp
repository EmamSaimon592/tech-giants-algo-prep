#include <iostream>

using namespace std;

// Define the modulo constant
const int MOD = 1000000007;

// Define the maximum constraint size
const int MAX_N = 1000001;

// Global array to store DP states (initialized to 0)
int dp[MAX_N];

int main() {
    int n;
    
    // Standard I/O
    if (!(cin >> n)) return 0;

    // Base case: There is 1 way to make the sum 0
    dp[0] = 1;

    // Fill the DP table up to n
    for (int i = 1; i <= n; i++) {
        // Check each possible dice roll (1 to 6)
        for (int die = 1; die <= 6; die++) {
            if (i - die >= 0) {
                dp[i] = (dp[i] + dp[i - die]) % MOD;
            }
        }
    }

    // Output the result for the sum n
    cout << dp[n] << endl;

    return 0;
}
