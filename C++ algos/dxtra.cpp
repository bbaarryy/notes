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
#include <stdio.h>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <cstdio>
#include <iomanip>

#define ll long long
#define REP(a) for (int i = 0; i < a; i++)
#define all(a) a.begin(), a.end()

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

struct doub
{
    ll vertex;
    ll dist;
    bool operator<(const doub &Other) const
    {
        if (dist == Other.dist)
        {
            return vertex < Other.vertex;
        }
        return dist < Other.dist;
    }
};

ll dxtra(vector<vector<pair<ll, ll>>> &matrix, ll start, ll finish, ll n)
{
    set<doub> setic;
    vector<ll> dist;
    dist.resize(n, 1e9);
    dist[start] = 0;
    setic.insert({0, 0});
    ll min_vertex, min_dist;
    while (!setic.empty())
    {
        min_vertex = setic.begin()->vertex;
        setic.erase(setic.begin());
        for (auto vrt : matrix[min_vertex])
        {
            if (dist[min_vertex] + vrt.second < dist[vrt.first])
            {
                setic.erase({vrt.first , dist[vrt.first]});
                dist[vrt.first] = dist[min_vertex] + vrt.second;
                setic.insert({vrt.first , dist[vrt.first]});
            }
        }
    }
    return dist[finish];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m, a, b, w;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> matrix(n);
    REP(m)
    {
        cin >> a >> b >> w;
        matrix[a - 1].push_back({b - 1, w});
        matrix[b - 1].push_back({a - 1, w});
    }
    ll start, finish;
    cin >> start >> finish;
    start--;
    finish--;
    cout << dxtra(matrix, start, finish, n);
}