#include<bits/stdc++.h>
#define gc getchar//_unlocked
#define pc putchar//_unlocked
#define f first
#define s second
#define pb push_back
#define MAX 200002
#define ll int
#define mod 1000000007

using namespace std;

ll f[100005];

/// array f has 1-based indexing and pattern has 0-based

void Failure(string s)
{
    ll len=s.length();   /// len is length of pattern
    f[0]=f[1]=0;         /// always true
    for(ll i=2;i<=len;i++)
    {
        ll j=f[i-1];     ///j is index of largest next partial match(suffix/prefix) of string under index i - 1
        while(1)
        {
            if(s[j]==s[i-1])  ///check if last character of string i - pattern[i - 1] "expands" the current prefix under index j
            {
                f[i]=j+1;
                break;
            }
            if(!j)     /// if we cannot "expand" even the empty string
            {
                f[i]=0;
                break;
            }
            j=f[j];    /// else go to the next best "candidate" partial previous match
        }
    }
}
ll kmp(string t,string p)
{
    Failure(p);
    ll match_count=0;
    ll m=p.length();
    ll n=t.length();
    ll j=0; /// index of string text
    ll i=0; /// index in pattern
    while(1)
    {
        if(j==n) break;   /// we reached the end of the text
        if(t[j]==p[i])    /// if the current character of the text "expands" the current match
        {
            i++;
            j++;
            if(i==m) match_count++;   /// match found
        }
        else if(i) i=f[i];     /// if current state is not zero we try to "expand" the next best (largest) match
        else j++;
    }
    return match_count;
}

int main()
{
	//freopen("x.txt","r",stdin);
	ll n,m,k;
    string t,p;
    cin>>t>>p;
    cout<<kmp(t,p);
	return 0;
}
