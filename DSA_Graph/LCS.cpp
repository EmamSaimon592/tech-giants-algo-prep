
/* 
আমাদের ২টা string দেওয়া আছে s এবং t।
এখন এমন একটি সবচেয়ে বড় subsequence বের করতে হবে যেটা দুই string এই common।
example:
s = axyb
t = abyxb

out: axb

মূল ধারণা (Dynamic Programming)

আমরা একটি dp[i][j] table বানাবো।

এখানে:
dp[i][j] =
s এর প্রথম i টা character
এবং
t এর প্রথম j টা character

এর মধ্যে LCS এর length
Relation

যদি character same হয়: s[i-1] == t[j-1]
তাহলে:dp[i][j] = dp[i-1][j-1] + 1
কারণ নতুন একটি common character পাওয়া গেছে।

যদি same না হয়: dp[i][j] = max(dp[i-1][j], dp[i][j-1])
এরপর string বের করবো কিভাবে?

DP table fill করার পরে backtracking করবো।

শেষ cell থেকে শুরু:
i = n
j = m
যদি character same হয়:
ans += s[i-1]
i--
j--
না হলে যেদিকে বড় value আছে সেদিকে move করবো।
*/


#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 3005;

char s[MAX], t[MAX];
int dp[MAX][MAX];

char ans[MAX];

int main() {

    cin >> s;
    cin >> t;

    int n = strlen(s);
    int m = strlen(t);

    // DP Table Fill
    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= m; j++) {

            if (s[i - 1] == t[j - 1]) {

                dp[i][j] = dp[i - 1][j - 1] + 1;

            } else {

                if (dp[i - 1][j] > dp[i][j - 1]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
    }

    // Backtracking
    int i = n;
    int j = m;

    int index = dp[n][m];

    ans[index] = '\0';

    while (i > 0 && j > 0) {

        // Character same
        if (s[i - 1] == t[j - 1]) {

            ans[index - 1] = s[i - 1];

            index--;

            i--;
            j--;
        }

        // Up direction
        else if (dp[i - 1][j] > dp[i][j - 1]) {

            i--;
        }

        // Left direction
        else {

            j--;
        }
    }

    cout << ans << endl;

    return 0;
}

