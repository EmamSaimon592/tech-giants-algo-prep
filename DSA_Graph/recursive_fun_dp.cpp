#include <iostream>

using namespace std;

int main() {
    int n, cases;
    int a, b, c, d, e, f;
    // n এর সর্বোচ্চ মান 10000, তাই অ্যারের সাইজ 10001
    int dp[10001]; 

    // টেস্ট কেস ইনপুট
    if (!(cin >> cases)) return 0;

    for (int caseno = 1; caseno <= cases; ++caseno) {
        // ইনপুট নেওয়া
        cin >> a >> b >> c >> d >> e >> f >> n;

        // বেস কেসগুলো সেট করা
        // ইনপুট বড় হতে পারে তাই শুরুতেই মোডুলাস করা নিরাপদ
        dp[0] = a % 10000007;
        dp[1] = b % 10000007;
        dp[2] = c % 10000007;
        dp[3] = d % 10000007;
        dp[4] = e % 10000007;
        dp[5] = f % 10000007;

        // ৫ এর বেশি n এর জন্য লুপ চালিয়ে আগের ৬টি মানের যোগফল বের করা
        for (int i = 6; i <= n; i++) {
            // যোগ করার সময় ডাটা টাইপ যেন ওভারফ্লো না করে তাই সাবধানে মোডুলাস করা
            long long sum = (long long)dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4] + dp[i - 5] + dp[i - 6];
            dp[i] = sum % 10000007;
        }

        // আউটপুট ফরম্যাট অনুযায়ী প্রিন্ট করা
        cout << "Case " << caseno << ": " << dp[n] % 10000007 << endl;
    }

    return 0;
}