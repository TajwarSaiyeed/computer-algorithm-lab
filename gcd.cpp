/*
    Author: Tajwar Saiyeed
    Date: 2025-08-12 10:57:16
    File: gcd1.cpp
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define yes cout << "YES" << '\n'
#define no cout << "NO" << '\n'
#define p1 cout << '1'
#define p0 cout << '0'
#define nl '\n'
#define vll vector<ll>
#define vi vector<int>
#define vs vector<string>
#define dt(n) fixed << setprecision(n)
typedef long long ll;


int gcd(int a, int b) {

    int mn = min(a, b);
    int mx = max(a, b);
    while (mn != 0) {
        int ans = mx % mn;
        mx = mn;
        mn = ans;
    }

    return mx;
}

void solve()
{
    int a, b;
    cin>>a>>b;
    cout<<gcd(a,b) <<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc = 1;
    // cin >> tc;

    while (tc--)
    {
        solve();
    }

    return 0;
}


// Problem : 