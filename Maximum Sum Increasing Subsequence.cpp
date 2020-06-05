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

int maxSumIncSub(vi &arr) {
    int n = arr.size();
    if (!n) return 0;
    int dp[n], ind[n];
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < n; i++) dp[i] = arr[i], ind[i] = i;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + arr[i]) {
                dp[i] = dp[j] + arr[i];
                ind[i] = j;
            }
        }
    }
    int *ans = max_element(dp, dp + n);
    int max_ind =  ans - dp;
    while (max_ind != ind[max_ind]) {
        cout << arr[max_ind] << " ";
        max_ind = ind[max_ind];
    }
    cout << arr[max_ind] << endl;
    return *ans;
}

int maxSumIncSubRecursive(vi &arr, int i, int ans) {
    int res = ans + arr[i];
    for (int k = i + 1; k < arr.size(); k++) {
        if (arr[i] < arr[k]) res = max(res, maxSumIncSubRecursive(arr, k, ans + arr[i]));
    }
    return res;
}

int sum[100] = {0};

int query(int x) {
    int ans = 0;
    while (x > 0) {
        ans = max(ans, sum[x]);
        x -= x & -x;
    }
    return ans;
}

void update(int x, int val, int n) {
    while (x <= n) {
        sum[x] = max(val, sum[x]);
        x += x & -x;
    }
}

int binaryTreeSolution(vi &arr) {
    int size = 0;
    map<int, int> compressedIndex;
    for (int i = 0; i < arr.size(); i++) compressedIndex[arr[i]] = 1;
    for (auto k : compressedIndex) compressedIndex[k.first] = ++size;
    for (int i = 0; i < arr.size(); i++) {
        update(compressedIndex[arr[i]], query(compressedIndex[arr[i]] - 1) + arr[i], size);
    }
    int ans = query(size);
    return ans;
}

int main() {
    clock_t tStart = clock();
    fastio;
    vi arr{4, 6, 1, 3, 8, 4, 6};
    cout << maxSumIncSub(arr) << endl << maxSumIncSubRecursive(arr, 0, 0)<<endl;
    cout << binaryTreeSolution(arr);
    printf("\nTime taken: %.2fms\n", (double)(clock() - tStart) / (CLOCKS_PER_SEC / 1000));
    return 0;
}