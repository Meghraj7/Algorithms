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

int minCostPath(vector<vi> matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    if (!n || !m) return 0;
    int dp[n][m];
    for (int i = 0; i < n; i++) dp[i][0] = matrix[i][0] + (i ? dp[i-1][0] : 0);
    for (int i = 0; i < m; i++) dp[0][i] = matrix[0][i] + (i ? dp[0][i-1] : 0);
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) dp[i][j] = matrix[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << dp[i][j] << " "; cout << endl;
    }
    // Backtracking to get the sequence
    int i = n-1, j = m-1;
    while (i >= 0 && j >= 0) {
        cout<<matrix[i][j]<<" ";
        if (dp[i-1][j] < dp[i][j-1]) i--;
        else j--;
    }
    cout<<endl;
    return dp[n-1][m-1];
}

int minCostPathRecursive(vector<vi> &matrix, int n, int m) {
    if (!n && !m) return matrix[n][m];
    if (!n) return matrix[n][m] + minCostPathRecursive(matrix, n, m - 1);
    if (!m) return matrix[n][m] + minCostPathRecursive(matrix, n-1, m);
    return matrix[n][m] + min(minCostPathRecursive(matrix, n, m - 1), minCostPathRecursive(matrix, n - 1, m));
}

int main() {
    clock_t tStart = clock();
    fastio;
    vector<vi> matrix{
        {1, 3, 5, 8},
        {4, 2, 1, 7},
        {4, 3, 2, 3}
    };
    cout << minCostPath(matrix) << endl << minCostPathRecursive(matrix, 2, 3);
    printf("\nTime taken: %.2fms\n", (double)(clock() - tStart) / (CLOCKS_PER_SEC / 1000));
    return 0;
}