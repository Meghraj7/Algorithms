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

int pickMaxSum(vi &arr, int n) {
    pi dp[n + 1][n + 1];
    memset(dp, 0, sizeof dp);
    for(int i=1;i<=n;i++) dp[i][i] = make_pair(arr[i-1], 0);
    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++) {
            int pick_left = dp[i+1][j].second + arr[i-1];
            int pick_right = dp[i][j-1].second + arr[j-1];
            if (pick_left > pick_right) dp[i][j] = make_pair(pick_left, dp[i+1][j].first);
            else dp[i][j] = make_pair(pick_right, dp[i][j-1].first);
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) cout<<"("<<dp[i][j].first<<", "<<dp[i][j].second<<")"<<"  "; cout<<endl;
    }
    return dp[1][n].first;
}

typedef map<tuple<int, int, bool>, int> _hash;
int pickMaxSumRecursive(vi &arr, int i, int j, bool turn, _hash hashmap) {
    if (i > j) return 0;
    if (i == j) return turn ? arr[i] : 0;
    if (hashmap.count({i,j,turn})) return hashmap[{i,j,turn}];
    if (turn) {
        int left_res = pickMaxSumRecursive(arr, i + 1, j, !turn, hashmap);
        int right_res = pickMaxSumRecursive(arr, i, j - 1, !turn, hashmap);
        hashmap[{i,j,turn}] = max(left_res + arr[i], right_res + arr[j]);
    } else hashmap[{i,j,turn}] =  arr[i] > arr[j] ? pickMaxSumRecursive(arr, i + 1, j, !turn, hashmap) : pickMaxSumRecursive(arr, i, j - 1, !turn, hashmap);
    return hashmap[{i,j,turn}];
}

int main() {
    clock_t tStart = clock();
    fastio;
    _hash hashmap;
    vi arr{3, 9, 1, 2};
    cout<<pickMaxSumRecursive(arr, 0, arr.size() - 1, true, hashmap)<<endl<<pickMaxSum(arr, arr.size());
    printf("\nTime taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}