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

int maxCuttingProfit(vi &arr, vi &price, int n) {
    int dp[arr.size() + 1][n + 1];
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; i++) dp[1][i] = price[0]*i;
    for (int i = 2; i <= arr.size(); i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i-1] <= j) dp[i][j] = max(dp[i - 1][j], dp[i][j - arr[i-1]] + price[i-1]);
            else dp[i][j] = dp[i - 1][j];
        }
    }
    // Backtracking to get the cut lengths
    int i = arr.size(), j = n;
    while (i * j) {
        if (dp[i][j] != dp[i - 1][j]) {
            cout << arr[i - 1] << " ";
            j -= arr[i - 1];
        } else i--;
    }
    cout << endl;
    return dp[arr.size()][n];
}

int maxCuttProfitRecursive(vi &arr, vi &price, int i, int len, int profit) {
    if (i == arr.size() || len < 0) return 0;
    if (len == 0) return profit;
    return max(noOfCoins(arr, price, i, len - arr[i], profit + price[i]), noOfCoins(arr, price, i+1, len, profit));
}

int main() {
    clock_t tStart = clock();
    fastio;
    vi arr{1, 2, 3, 5}, price{2, 5, 7, 8};
    cout<<maxCuttingProfit(arr, price, 5)<<endl<<maxCuttProfitRecursive(arr, price, 0, 5, 0);
    printf("\nTime taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}