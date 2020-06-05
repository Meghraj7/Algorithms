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

int minEditDistance(string s, string t) {
    int dp[s.length() + 1][t.length() + 1];
    memset(dp, 0, sizeof dp);
    for (int i = 0; i <= s.length(); i++) dp[i][0] = i;
    for (int i = 0; i <= t.length(); i++) dp[0][i] = i;
    for (int i = 1; i <= s.length(); i++) {
        for (int j = 1; j <= t.length(); j++) {
            if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
        }
    }
    return dp[s.length()][t.length()];
}

int minEditDistanceRecursive(string &s, string &t, int i, int j) {
    if (i < 0) return j + 1;
    if (j < 0) return i + 1;
    if (s[i] == t[j]) return minEditDistanceRecursive(s, t, i - 1, j - 1);
    return 1 + min(minEditDistanceRecursive(s, t, i - 1, j - 1),
                   min(minEditDistanceRecursive(s, t, i, j - 1), minEditDistanceRecursive(s, t, i - 1, j)));
}

int main() {
    clock_t tStart = clock();
    fastio;
    map<pi, int> hashmap;
    string str1 = "abcdef", str2 = "acbcdtf";
    cout << minEditDistance(str1, str2) << endl << minEditDistanceRecursive(str1, str2, str1.length() - 1, str2.length() - 1);
    printf("\nTime taken: %.2fms\n", (double)(clock() - tStart) / (CLOCKS_PER_SEC / 1000));
    return 0;
}