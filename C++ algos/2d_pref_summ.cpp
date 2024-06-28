// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("inline")

#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <set>
#include <cmath>
#include <stack>
#include <string>
#include <queue>
#include <chrono>
#include <sstream>
#include <stdio.h>
#include <unordered_map>

#define ll long long

using namespace std;

template <typename T>
istream &operator>>(istream &in, vector<T> &a)
{
    for (auto &i : a)
        in >> i;
    return in;
}

template <typename T>
ostream &operator<<(ostream &out, const vector<T> &a)
{
    for (auto &i : a)
    {
        out << i << ' ';
    }
    return out;
}

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    a %= b;
    return gcd(b, a);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t, n, m, k;

    cin >> n >> m;
    vector<vector<ll>> arr(n, vector<ll>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    vector<vector<ll>> pref(n, vector<ll>(m));
    pref[0][0] = arr[0][0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j != 0)
            {
                pref[i][j] = pref[i][j - 1] + arr[i][j];
            }
            if (j == 0 && i != 0)
            {
                pref[i][j] = pref[i - 1][j] + arr[i][j];
            }
            if (i != 0 && j != 0)
            {
                pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + arr[i][j];
            }
        }
    }

    vector<ll> summs;
    ll q, x1, x2, y1, y2;
    cin >> q;
    while (q--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        //x1,y1 - граница правого нижнего угла
        //x2,y2 - граница верхнего левого угла
        x1--;
        x2--;
        y1--;
        y2--;
        ll curr_summ;
        if (y2 == 0 && x2 == 0)
        {
            curr_summ = pref[x1][y1];
        }

        else if (y2 == 0)
        {
            curr_summ = pref[x1][y1] - pref[x2 - 1][y1];
        }
        else if (x2 == 0)
        {
            curr_summ = pref[x1][y1] - pref[x1][y2 - 1];
        }
        else
        {
            curr_summ = pref[x1][y1] - pref[x2 - 1][y1] - pref[x1][y2 - 1] + pref[x2 - 1][y2 - 1];
        }
        cout << curr_summ << '\n';
    }
}