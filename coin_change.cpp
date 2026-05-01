#include <iostream>

using namespace std;

const int MOD = 1000000007;

// x এর সর্বোচ্চ মান 10^6, তাই গ্লোবাল অ্যারে নেওয়া ভালো
int dp[1000001];
int coins[101];

int main() {
    int n, x;
    
    // ইনপুট দ্রুত করার জন্য (ঐচ্ছিক কিন্তু ভালো প্র্যাকটিস)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> x)) return 0;

    // কয়েনগুলোর মান ইনপুট নেওয়া
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    // বেস কেস: ০ সাম বানানোর ১টি উপায় আছে
    dp[0] = 1;

    // আমরা প্রতিটি সাম i এর জন্য সব কয়েন চেক করব
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            // যদি বর্তমান সাম i থেকে কয়েনের মান ছোট বা সমান হয়
            if (i - coins[j] >= 0) {
                dp[i] = (dp[i] + dp[i - coins[j]]) % MOD;
            }
        }
    }

    // আউটপুট প্রিন্ট করা
    cout << dp[x] << endl;

    return 0;
}

