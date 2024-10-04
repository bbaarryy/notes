#include <bits/stdc++.h>

using namespace std;

#define ll int
#define all(a) a.begin(), a.end()
#define REP(a) for (int i = 0; i < a; i++)

ll MOD = 1e9 + 7;

template <typename T>
istream& operator>>(istream& in, vector<T>& a)
{
    for (auto& i : a)
        in >> i;
    return in;
}

template <typename T>
ostream& operator<<(ostream& out, const vector<T>& a)
{
    for (auto& i : a)
    {
        out << i << " ";
    }
    return out;
}

vector<ll> depth;//массив глубин каждой из вершин
vector<bool> used;
vector<ll> up;//up[i]-самая неглубокая вершина , куда ведет обратное ребро , для поддерева вершины i
set<ll> dots;//множество точек сочленения

void dfs(ll curr, ll last, vector<vector<ll>>& matrix, ll root) {
    used[curr] = 1;
    ll sch = 0;
    for (auto nxt : matrix[curr]) {
        if (!used[nxt]) {//не были в ней , не обратное ребро
            depth[nxt] = depth[curr] + 1;
            sch++;
            dfs(nxt, curr, matrix, root);
            if (up[nxt] >= depth[curr]) {//если у нас обратное ребро из поддерева глубже чем глубина рассматриваемой вершины 
                if (matrix[curr].size() > 1 && curr != root) {//если это не лист и не корень , то подходит
                    dots.insert(curr + 1);
                }
            }
            up[curr] = min(up[curr], up[nxt]);
        }
        else if (used[nxt]) {//были в ней , значит это обратное ребро
            up[curr] = min(up[curr], depth[nxt]);
        }
        if (curr == root) {//если это корень , то должно быть хотя бы 2 запуска дфс из него
            if (sch > 1) {
                dots.insert(curr + 1);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, m, x, y;
    cin >> n >> m;
    vector<vector<ll>> matrix(n);
    depth.resize(n, 0);
    used.resize(n, 0);
    up.resize(n, 1e9);
    REP(m) {
        cin >> x >> y;
        matrix[x - 1].push_back(y - 1);
        matrix[y - 1].push_back(x - 1);
    }

    dfs(0, 0, matrix, 0);
    REP(n) {
        if (!used[i]) {
            dfs(i, i, matrix, i);
        }
    }
    cout << dots.size() << '\n';
    for (auto i : dots) { cout << i << ' '; }

}