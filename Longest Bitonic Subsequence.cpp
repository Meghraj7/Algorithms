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

vi LIS(vi arr) {
    vi dp;
    dp.resize(arr.size(), 1);
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < i; j++) if (arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + 1);
    }
    return dp;
}

int maxBitonicLength(vi &arr) {
    vi left_LIS = LIS(arr);
    reverse(arr.begin(), arr.end());
    vi right_LIS = LIS(arr);
    reverse(right_LIS.begin(), right_LIS.end());
    vi result;
    transform(left_LIS.begin(), left_LIS.end(), right_LIS.begin(), back_inserter(result), plus<int>());
    return *max_element(result.begin(), result.end()) - 1;
}

int main() {
    clock_t tStart = clock();
    fastio;
    vi arr{2, -1, 4, 3, 5, -1, 3, 2};
    cout << maxBitonicLength(arr);
    printf("\nTime taken: %.2fms\n", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000));
    return 0;
}