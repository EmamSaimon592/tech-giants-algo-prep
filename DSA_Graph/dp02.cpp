#include <iostream>
#include <iomanip>

using namespace std;

// N এর সর্বোচ্চ মান ২৯৯৯, তাই আমরা ৩০০০ সাইজের অ্যারে নিচ্ছি
double dp[3005][3005];
double p[3005];

int main() {
    int n;
    if (!(cin >> n)) return 0;

    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    // শুরুতে সব ০ করে দেওয়া
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0.0;
        }
    }

    // বেস কেস
    dp[0][0] = 1.0;

    // DP টেবিল ফিলআপ করা
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            // যদি কারেন্ট কয়েন Heads হয়
            if (j > 0) {
                dp[i][j] += dp[i - 1][j - 1] * p[i];
            }
            // যদি কারেন্ট কয়েন Tails হয়
            dp[i][j] += dp[i - 1][j] * (1.0 - p[i]);
        }
    }

    double total_probability = 0.0;
    // Heads এর সংখ্যা Tails এর চেয়ে বেশি হতে হলে 
    // j > n/2 হতে হবে
    for (int j = (n / 2) + 1; j <= n; j++) {
        total_probability += dp[n][j];
    }

    // দশমিকের পর ১০ ঘর পর্যন্ত নিখুঁত আউটপুট
    cout << fixed << setprecision(10) << total_probability << endl;

    return 0;
}