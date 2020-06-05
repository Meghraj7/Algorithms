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

int maxSubsquare(vector<vi> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vpi> dp(n, vpi (m, {0, 0}));
    dp[0][0] = matrix[0][0] ? make_pair(1, 1) : make_pair(0, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!i && !j) continue;
            if (i && !j)  dp[i][j] = make_pair(1 + dp[i - 1][j].f, 1);
            else if (!i && j)  dp[i][j] = make_pair(1, 1 + dp[i][j - 1].s);
            else if (matrix[i][j]) dp[i][j] = make_pair(1 + dp[i - 1][j].f, 1 + dp[i][j - 1].s);
        }
    }
    int ans = 1;
    for (int i = n - 1; i > 0; i--) {
        for (int j = m - 1; j > 0; j--) {
            int min_val = min(dp[i][j].f, dp[i][j].s);
            while (ans < min_val) {
                if (min_val <= min(dp[i - min_val + 1][j].s , dp[i][j - min_val + 1].f)) ans = min_val;
                min_val--;
            }
        }
    }
    return ans;
}

int main() {
    clock_t tStart = clock();
    fastio;
    vector<vi> matrix{
        {0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1},
        {1, 0, 1, 0, 1},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 1, 1}
    };
    cout << maxSubsquare(matrix);
    printf("\nTime taken: %.2fms\n", (double)(clock() - tStart) / (CLOCKS_PER_SEC / 1000));
    return 0;
}