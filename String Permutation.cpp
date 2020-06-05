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

void stringPermutation(string t, int n, vi &hashmap) {
    if (t.length() == n) {
        cout<<t<<endl;
        return;
    }
    for(int i=0;i<26;i++) {
        if (hashmap[i]) {
            string s(1, a + 'A');
            t += s;
            --hashmap[i];
            stringPermutation(t, n, hashmap);
            ++hashmap[i];
            t.pop_back();
        }
    }
}

int main() {
    clock_t tStart = clock();
    fastio;
    string s = "AABC", t = "";
    vi hashmap;
    hashmap.resize(26, 0);
    for(int i=0;i<s.length();i++) hashmap[s[i] - 'A']++;
    stringPermutation(t, s.length(), hashmap);// << endl << stringInterleavingSubRecursive(a, b, c, a.length(), b.length()) << endl;
    printf("\nTime taken: %.2fms\n", (double)(clock() - tStart) / (CLOCKS_PER_SEC / 1000));
    return 0;
}