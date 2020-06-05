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
#define pi pair< ll, ll >
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

int solveNN(vi arr) {
    vi dp, parent, longest_sequence;
    dp.resize(arr.size(), 1);
    parent.resize(arr.size());
    iota(parent.begin(), parent.end(), 0);
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < i; j++) if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
                parent[i] = j;
            }
    }

    //Print the longest increasing subsequence
    int ind = max_element(dp.begin(), dp.end()) - dp.begin();
    while (ind != parent[ind]) {
        longest_sequence.push_back(arr[ind]);
        ind = parent[ind];
    }
    longest_sequence.push_back(arr[ind]);
    reverse(longest_sequence.begin(), longest_sequence.end());
    return *max_element(dp.begin(), dp.end());
}

int solveNlogN(vi arr) {
    vi dp;
    dp.push_back(arr[0]);
    for (int i = 0; i < arr.size(); i++) {
        auto curr_longest_len = lower_bound(dp.begin(), dp.end(), arr[i]);
        if (curr_longest_len == dp.end()) dp.push_back(arr[i]);
        else *curr_longest_len = arr[i];
    }
    return dp.size();
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
        update(compressedIndex[arr[i]], query(compressedIndex[arr[i]] - 1) + 1, size);
    }
    int ans = query(size);
    return ans;
}

int main() {
    clock_t tStart = clock();
    fastio;
    vi arr{2, 5, 3, 7, 11, 8, 10, 13, 6};
    cout << solveNN(arr) << endl << solveNlogN(arr) << endl;
    cout << binaryTreeSolution(arr);
    printf("\nTime taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}