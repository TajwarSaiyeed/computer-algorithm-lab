/*
    Author: Tajwar Saiyeed
    Date: 2025-11-04 10:52:19
    File: quick.cpp
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

int part(vector<int> &arr, int l, int r)
{
    int pivot = arr[l];
    int l_p = l + 1;
    int r_p = r;

    while (l_p <= r_p)
    {
        while (l_p <= r && arr[l_p] <= pivot)
        {
            l_p++;
        }

        while (r_p >= l && arr[r_p] > pivot)
        {
            r_p--;
        }

        if (l_p < r_p)
        {
            swap(arr[l_p], arr[r_p]);
        }
    }

    swap(arr[l], arr[r_p]);
    return r_p;
}

void quick_sort(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        int x = part(arr, l, r);
        cout << "Part of : " << x << " ";
        for (int i = 0; i  < x; i ++ ){
            cout << arr[i] <<  " ";
        }

        cout  <<nl;
        quick_sort(arr, l, x - 1);
        quick_sort(arr, x + 1, r);
    }
}

void solve()
{
    vector<int> arr = {3, 6, 8, 10, 1, 2, 1};
    int l = 0;
    int r = arr.size();
    quick_sort(arr, l, r - 1);
    for (int i = 0; i < r; i++)
    {
        cout << arr[i] << " ";
    }
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