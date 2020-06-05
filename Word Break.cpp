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

map<string, int> dict = {{"i", 1}, {"a", 1}, {"am", 1}, {"ace", 1}};

bool isWordInDictionary(string s) {
    if (dict.count(s)) return true;
    return false;
}

bool wordBreak(string s) {
    int n = s.length();
    if (!n) return false;
    bool dp[n][n];
    memset(dp, false, sizeof dp);
    for (int len = 1; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            dp[i][i + len - 1] = isWordInDictionary(s.substr(i, len));
            if (!dp[i][i + len - 1]) {
                for (int j = i + 1; j < i + len; j++) dp[i][i + len - 1] |= dp[i][j - 1] & dp[j][i + len - 1];
            }
        }
    }
    return dp[0][n - 1];
}

int wordBreakRecursive(string &s, int i, int j) {
    if (i > j) return false;
    bool res = isWordInDictionary(s.substr(i, j - i + 1));
    if (res) return true;
    for (int k = i + 1; k < j; k++) res |= wordBreakRecursive(s, i, k - 1) & wordBreakRecursive(s, k, j);
    return res;
}

int main() {
    clock_t tStart = clock();
    fastio;
    string s = "iamace";
    cout << wordBreak(s) << endl << wordBreakRecursive(s, 0, 5);
    printf("\nTime taken: %.2fms\n", (double)(clock() - tStart) / (CLOCKS_PER_SEC / 1000));
    return 0;
}