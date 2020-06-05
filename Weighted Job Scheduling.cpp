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

bool compare(pi &l, pi &r) {
    if (l.s == r.s) return l.f < r.f;
    return l.s < r.s;
}

bool isOverlap(pi &a, pi &b) {
    return a.s > b.f;
}

int weightedJobSchedulingBinarySearch(vector<pi> &arr, vi &profit) {
    sort(arr.begin(), arr.end(), compare);
    int n = arr.size();
    vi dp;
    dp[0] = profit[0];
    for(int i=1;i<n;i++) {
        int idx = lower_bound(arr.begin(), arr.end(), make_pair(0, arr[i].f), [](pi a, pi b) {
            return a.s <= b.s;
        }) - arr.begin();
        if (idx) dp[i] = max(dp[i-1], profit[i] + dp[idx - 1]);
        else dp[i] = dp[i-1];
    }
    return *max_element(dp.begin(), dp.end());
}

int weightedJobScheduling(vector<pi> &arr, vi &pay) {
    sort(arr.begin(), arr.end(), compare);
    int n = arr.size();
    vi dp = pay;
    for(int i=1;i<n;i++) {
        for(int j=0;j<i;j++) {
            if(!isOverlap(arr[j], arr[i])) dp[i] = max(dp[i], pay[i] + dp[j]); 
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int main() {
    clock_t tStart = clock();
    fastio;
    //vector<pi> arr{{1,3}, {6,7}, {2,5}, {7,9}, {4,6}, {5,8}};
    vector<pi> arr{{1,4}, {2,5}, {6,7}};
    vi profit{100, 5, 15};
    cout<<weightedJobScheduling(arr, pay)<<endl<<weightedJobSchedulingBinarySearch(arr, pay);
    printf("\nTime taken: %.2fms\n", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000));
    return 0;
}