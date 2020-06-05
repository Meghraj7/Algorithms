#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

#define gc getchar_unlocked
#define pc putchar_unlocked
#define pb push_back

#define mp make_pair
#define f first
#define s second
#define mod 1000000007
#define PI 3.14159265
#define ll unsigned long long
#define pi pair< int, int >
#define vi vector< int >
#define vll vector< ll >
#define vvll vector< vector< ll > >
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define For(a,b) for(int i=a;i<=b;i++)

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() { cerr << endl;}

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int LPalinSubsequence(string s) {
    int n = s.length();
    if (!n) return 0;
    int dp[n][n];
    memset(dp, 0, sizeof dp);
    for (int len = 1; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            if (len == 1) {
                dp[i][i] = 1;
                continue;
            }
            if (s[i] == s[i + len - 1]) dp[i][i + len - 1] = 2 + dp[i + 1][i + len - 2];
            else dp[i][i + len - 1] = max(dp[i + 1][i + len - 1], dp[i][i + len - 2]);
        }
    }
    return dp[0][n - 1];
}

int LPalinSubsequenceRecursive(string &s, int i, int j) {
    if (i > j) return 0;
    if (i == j) return 1;
    if (s[i] == s[j]) return 2 + LPalinSubsequenceRecursive(s, i + 1, j - 1);
    return max(LPalinSubsequenceRecursive(s, i + 1, j), LPalinSubsequenceRecursive(s, i, j - 1));
}

int main() {
    clock_t tStart = clock();
    fastio;
    string s = "agbdba";
    cout << LPalinSubsequence(s) << endl << LPalinSubsequenceRecursive(s, 0, 5);
    printf("\nTime taken: %.2fms\n", (double)(clock() - tStart) / (CLOCKS_PER_SEC / 1000));
    return 0;
}