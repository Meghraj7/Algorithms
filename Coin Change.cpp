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

int noOfWaysToSumN(vi &arr, int n) {
    int dp[n + 1][arr.size() + 1];
    memset(dp, 0, sizeof dp);
    for (int i = 0; i <= n; i++) dp[i][0] = dp[0][i] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= arr.size(); j++) {
            if (i >= arr[j]) dp[i][j] = dp[i][j - 1] + dp[i - arr[j]][j];
            else dp[i][j] = dp[i][j - 1];
        }
    }
    return dp[n][arr.size()];
}

int minimumNoOfCoinsToSumN(vi &arr, int n) {
    int dp[arr.size() + 1][n + 1];
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; i++) dp[0][i] = i;
    for (int i = 1; i <= arr.size(); i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i - 1] <= j) dp[i][j] = min(dp[i - 1][j], dp[i][j - arr[i - 1]] + 1);
            else dp[i][j] = dp[i - 1][j];
        }
    }
    // Backtracking to get the coins
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

int noOfWays(vi &arr, int i, int sum) {
    if (i == arr.size() || sum < 0) return 0;
    if (sum == 0) return 1;
    return noOfWays(arr, i, sum - arr[i]) + noOfWays(arr, i+1, sum);
}

int noOfCoins(vi &arr, int i, int sum, int coin) {
    if (i == arr.size() || sum < 0) return INT_MAX;
    if (sum == 0) return coin;
    return min(noOfCoins(arr, i, sum - arr[i], coin+1), noOfCoins(arr, i+1, sum, coin));
}

int main() {
    clock_t tStart = clock();
    fastio;
    vi arr{1, 2, 3, 5};
    cout<<noOfWays(arr, 0, 8)<<endl<<noOfCoins(arr, 0, 8, 0);
    //cout<<noOfWaysToSumN(arr, 8)<<endl<<minimumNoOfCoinsToSumN(arr, 11);
    printf("\nTime taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}