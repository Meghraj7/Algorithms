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

int minJumpToReachEnd(vi &arr) {
    int n = arr.size();
    int dp[n];
    for (int i = 0; i < n; i++) dp[i] = INT_MAX;
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= arr[i]; j++) {
            if (i + j >= n) continue;
            dp[i + j] = min(dp[i + j], 1 + dp[i]);
        }
    }
    return dp[n - 1];
}

int minJumpToReachEndRecursive(vi &arr, int i, int ans) {
    if (i >= arr.size()) return INT_MAX;
    if (i == arr.size()-1) return ans;
    int res = INT_MAX;
    for (int j = 1; j <= arr[i]; j++) res = min(res, minJumpToReachEndRecursive(arr, i + j, ans + 1));
    return res;
}

int main() {
    clock_t tStart = clock();
    fastio;
    vi arr{2, 3, 1, 1, 2, 4, 2, 0, 1, 1};
    cout << minJumpToReachEnd(arr) << endl << minJumpToReachEndRecursive(arr, 0, 0); 
    printf("\nTime taken: %.2fms\n", (double)(clock() - tStart) / (CLOCKS_PER_SEC / 1000));
    return 0;
}