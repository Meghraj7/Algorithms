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

int maxSubSquareMatrix(vector<vi> matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    if (!n || !m) return 0;
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof dp);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (matrix[i - 1][j - 1]) dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}

pi maxSubSquareMatrixRecursive(vector<vi> &matrix, int n, int m) {
    if (n < 0 || m < 0) return {0,0};
    pi a = maxSubSquareMatrixRecursive(matrix, n - 1, m - 1);
    pi b = maxSubSquareMatrixRecursive(matrix, n, m - 1);
    pi c = maxSubSquareMatrixRecursive(matrix, n - 1, m);
    int ans = 0;
    if (matrix[n][m]) ans = 1 + min(a.f, min(b.f, c.f));
    int res = max(a.s, max(b.s, c.s));
    res = max(res, ans);
    return {ans, res};
}

int main() {
    clock_t tStart = clock();
    fastio;
    vector<vi> matrix{
        {0, 0, 1, 1, 1},
        {1, 0, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {1, 0, 1, 1, 1}
    };
    cout << maxSubSquareMatrix(matrix);
    cout << endl<<maxSubSquareMatrixRecursive(matrix, matrix.size() - 1, matrix[0].size() - 1).s;
    printf("\nTime taken: %.2fms\n", (double)(clock() - tStart) / (CLOCKS_PER_SEC / 1000));
    return 0;
}