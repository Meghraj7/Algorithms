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

bool stringInterleaving(string &a, string &b, string &s) {
    if (a.length() + b.length() != s.length()) return false;
    if (!a.length() && !b.compare(s)) return false;
    if (!b.length() && !a.compare(s)) return false;
    int n = a.length();
    int m = b.length();
    int dp[n + 1][m + 1];
    memset(dp, false, sizeof dp);
    dp[0][0] = true;
    for (int i = 1; i <= m; i++) dp[0][i] = dp[0][i - 1] & (b[i - 1] == s[i - 1]);
    for (int i = 1; i <= n; i++) dp[i][0] = dp[i - 1][0] & (a[i - 1] == s[i - 1]);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == s[i + j - 1]) dp[i][j] = dp[i - 1][j];
            else if (b[j - 1] == s[i + j - 1]) dp[i][j] = dp[i][j - 1];
        }
    }
    return dp[n][m];
}

int stringInterleavingSubRecursive(string &a, string &b, string &s, int i, int j) {
    if (!i && !j) return true;
    if (!i) return (b[j - 1] == s[j - 1]) ? stringInterleavingSubRecursive(a, b, s, i, j - 1) : false;
    if (!j) return (a[i - 1] == s[i - 1]) ? stringInterleavingSubRecursive(a, b, s, i - 1, j) : false;
    bool ans = false;
    if (a[i - 1] == s[i + j - 1]) ans = stringInterleavingSubRecursive(a, b, s, i - 1, j);
    else if (b[j - 1] == s[i + j - 1]) ans = stringInterleavingSubRecursive(a, b, s, i, j - 1);
    return ans;
}

int main() {
    clock_t tStart = clock();
    fastio;
    string a = "axy", b = "aab", c = "aaxaby";
    cout << stringInterleaving(a, b, c) << endl << stringInterleavingSubRecursive(a, b, c, a.length(), b.length()) << endl;
    printf("\nTime taken: %.2fms\n", (double)(clock() - tStart) / (CLOCKS_PER_SEC / 1000));
    return 0;
}