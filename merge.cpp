/*
    Author: Tajwar Saiyeed
    Date: 2025-11-04 10:58:59
    File: merge.cpp
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


int mergeSort(vector<int> &arr, int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, l, mid, r);
    }
}

int merge(vector<int> & arr, int l, int mid, int r) {
    int x = mid - l + 1;
    int y = r - mid;

    vector<int> L = copy(arr, arr + x);
    vector<int> R = copy, 
}


void solve()
{
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc = 1;
    cin >> tc;

    while (tc--)
    {
        solve();
    }

    return 0;
}


// Problem : 