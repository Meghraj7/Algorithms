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

int subsetSum(vi &arr, int sum) {
    int n = arr.size();
    bool dp[n + 1][sum + 1];
    memset(dp, false, sizeof dp);
    for (int i = 0; i <= n; i++) dp[i][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            if (j >= arr[i - 1]) dp[i][j] = dp[i - 1][j] | dp[i - 1][j - arr[i - 1]];
            else dp[i][j] = dp[i - 1][j];
        }
    }
    // Backtracking to get the subset
    int i = n, j = sum;
    while (i * j) {
        if (dp[i][j] == dp[i - 1][j]) i--;
        else {
            cout << arr[i - 1] << " ";
            j -= arr[i - 1];
        }
    }
    cout << endl;
    return dp[n][sum];
}

bool subsetSumRecursive(vi &arr, int i, int j, map<pi, bool> &hashmap) {
    if (!j) return true;
    if (!i) return false;
    pi state = make_pair(i, j);
    if (hashmap.count(state)) return hashmap[state];
    if (j < arr[i - 1]) hashmap[state] = subsetSumRecursive(arr, i - 1, j, hashmap);
    else hashmap[state] = subsetSumRecursive(arr, i - 1, j, hashmap) |
                              subsetSumRecursive(arr, i - 1, j - arr[i - 1], hashmap);
    return hashmap[state];
}

int main() {
    clock_t tStart = clock();
    fastio;
    map<pi, bool> hashmap;
    vi arr{2, 3, 7, 8, 10};
    cout << subsetSum(arr, 11) << endl << subsetSumRecursive(arr, 5, 11, hashmap);
    printf("\nTime taken: %.2fms\n", (double)(clock() - tStart) / (CLOCKS_PER_SEC / 1000));
    return 0;
}