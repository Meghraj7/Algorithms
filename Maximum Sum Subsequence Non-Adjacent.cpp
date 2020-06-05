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
#define vpi vector< pi >
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

int maxSumNonAdjacent(vi &arr) {
    int n = arr.size(), dp[n];
    memset(dp, 0, sizeof dp);
    dp[0] = arr[0];
    dp[1] = max(dp[0], arr[1]);
    for (int i = 2; i < n; i++) dp[i] = max(dp[i - 1], arr[i] + dp[i - 2]);
    return dp[n - 1];
}

int maxSumNonAdjacentRecursive(vi &arr, int i) {
    if (!i) return arr[0];
    if (i == 1) return max(arr[0], arr[1]);
    return max(maxSumNonAdjacentRecursive(arr, i - 1), arr[i] + maxSumNonAdjacentRecursive(arr, i - 2));
}

int main() {
    clock_t tStart = clock();
    fastio;
    vi arr{4, 1, 1, 4, 2, 1};
    cout << maxSumNonAdjacent(arr) << endl << maxSumNonAdjacentRecursive(arr, arr.size() - 1) << endl;
    printf("\nTime taken: %.2fms\n", (double)(clock() - tStart) / (CLOCKS_PER_SEC / 1000));
    return 0;
}