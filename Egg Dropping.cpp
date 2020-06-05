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

int eggDropMinAttempt(int eggs, int floors) {
    if (!floors || !eggs) return 0;
    int dp[eggs + 1][floors + 1];
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= floors; i++) dp[1][i] = i;
    for (int egg = 2; egg <= eggs; egg++) {
        for (int floor = 1; floor <= floors; floor++) {
            if (egg > floor) {
                dp[egg][floor] =  dp[egg - 1][floor];
            }
            int res = INT_MAX;
            for (int k = 1; k <= floor; k++) res = min(res, max(dp[egg - 1][k - 1], dp[egg][floor - k]));
            dp[egg][floor] = 1 + res;
        }
    }
    return dp[eggs][floors];
}

int eggDropMinAttemptRecursive(int eggs, int floors) {
    if (eggs == 1) return floors;
    if (eggs > floors) return eggDropMinAttemptRecursive(eggs - 1, floors);
    int res = INT_MAX;
    for (int floor = 1; floor <= floors; floor++) res = min(res, 
        max(eggDropMinAttemptRecursive(eggs - 1, floor - 1), eggDropMinAttemptRecursive(eggs, floors - floor)));
    return 1 + res;
}

int main() {
    clock_t tStart = clock();
    fastio;
    cout << eggDropMinAttempt(2, 19) << endl << eggDropMinAttemptRecursive(2, 19);
    printf("\nTime taken: %.2fms\n", (double)(clock() - tStart) / (CLOCKS_PER_SEC / 1000));
    return 0;
}