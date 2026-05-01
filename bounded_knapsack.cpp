#include <iostream>

using namespace std;

const int MOD = 100000007;

int main() {
    int T;
    // টেস্ট কেস ইনপুট
    if (!(cin >> T)) return 0;

    for (int t = 1; t <= T; t++) {
        int n, K;
        cin >> n >> K;

        int A[51], C[51];
        // কয়েনগুলোর মান ইনপুট
        for (int i = 0; i < n; i++) cin >> A[i];
        // কয়েনগুলোর সংখ্যা (সীমা) ইনপুট
        for (int i = 0; i < n; i++) cin >> C[i];

        // dp[i] দিয়ে বোঝায় 'i' অ্যামাউন্ট তৈরি করার উপায়
        int dp[1001];
        // শুরুতে সব ০ করে দেওয়া
        for (int i = 0; i <= K; i++) dp[i] = 0;
        
        // বেস কেস: ০ অ্যামাউন্ট তৈরি করার ১টি উপায় আছে
        dp[0] = 1;

        // প্রতিটি আলাদা কয়েনের জন্য লুপ
        for (int i = 0; i < n; i++) {
            // কয়েন i ব্যবহার করে বর্তমান DP টেবিল আপডেট করা
            // বড় থেকে ছোট লুপ (Reverse Loop) যাতে একই কয়েন লিমিটের বেশি ব্যবহার না হয়
            for (int j = K; j >= 0; j--) {
                // আমরা ১ থেকে Ci টি পর্যন্ত কয়েন যোগ করতে পারি
                for (int count = 1; count <= C[i]; count++) {
                    int val = count * A[i];
                    if (j - val >= 0) {
                        dp[j] = (dp[j] + dp[j - val]) % MOD;
                    } else {
                        break; // অ্যামাউন্ট নেগেটিভ হয়ে গেলে আর দেখার দরকার নেই
                    }
                }
            }
        }

        cout << "Case " << t << ": " << dp[K] << endl;
    }

    return 0;
}

