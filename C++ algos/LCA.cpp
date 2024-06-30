#include <bits/stdc++.h>

using namespace std;

#define ll long long

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
    int maximum;
    ll ind;
};

// О(n*log(n))
vector<vector<doub>> build_sparse_table(const vector<int> &arr)
{ // arr - массив , на котором надо построить разреженную таблицу
    ll n = arr.size();
    int maxpow = ceil(log2(n + 1));                        // 2^{maxpow} > n
    vector<vector<doub>> sparse(maxpow, vector<doub>(n)); // массив, где одно измерение - длина отрезка(степень двойки!), а другое - левая граница
    // sparse[0] = arr;
    for (int i = 0; i < n; i++)
    {
        sparse[0][i] = {arr[i], i};
    }
    for (int k = 0; k + 1 < maxpow; k++)
    { // перебор длины - степени двойки
        for (int ind = 0; ind + (1 << k) < n; ind++)
        { // перебор левой границы
            // ind+(1<<k) , чтобы отрезок не вылезал за границы массива
            if (sparse[k][ind].maximum < sparse[k][ind + (1 << k)].maximum)
            {
                sparse[k + 1][ind] = {sparse[k][ind].maximum, sparse[k][ind].ind};
            }
            else
            {
                sparse[k + 1][ind] = {sparse[k][ind + (1 << k)].maximum, sparse[k][ind + (1 << k)].ind};
            }
        }
    }
    return sparse;
}

doub get_ans(ll l, ll r, vector<int> &logs, vector<vector<doub>> &sparce_table)
{
    r++;// т.к. мы всё делаем на полуинтервалах
    int maxlog = logs[r - l]; // считаем такую наибольшую степень двойки, которая меньше r-l
    if (sparce_table[maxlog][l].maximum < sparce_table[maxlog][r - (1 << maxlog)].maximum)
    {
        return sparce_table[maxlog][l];
    }
    else
    {
        return sparce_table[maxlog][r - (1 << maxlog)];
    }
}

vector<int> eil;
vector<int> weights;
map<int,ll> indxs;
vector<bool> used;
void dfs(int curr, const vector<vector<ll>> &matrix,ll weight)
{
    used[curr] = 1;
    for (auto vrt : matrix[curr])
    {
        if (!used[vrt])
        {
            eil.push_back(curr);
            weights.push_back(weight);
            indxs[curr]=eil.size()-1;
            dfs(vrt, matrix,weight+1);
        }
    }
    weights.push_back(weight);
    eil.push_back(curr);
    indxs[curr]=eil.size()-1;
}

int main()
{

    ll n,m,a;
    cin >> n>>m;

    vector<vector<ll>> matrix(n);

    for (int i = 0; i < n-1; i++)
    {
        cin >> a;
        matrix[a].push_back(i + 1);
        matrix[i + 1].push_back(a);
    }

    // эйлеров обход дерева
    used.resize(n, 0);
    dfs(0, matrix,0);

    vector<int> logs(eil.size() + 1); // предпосчитаем log2 для каждого числа
    logs[1] = 0;
    for (int i = 2; i <= eil.size(); i++)
    {
        // если для i/2 требуется k делений нацело пополам , то для i - k+1. Log2 - это количество делений числа нацело на два, прежде чем оно станет 1
        logs[i] = logs[i >> 1] + 1;
    }

    vector<vector<doub>> sparce_table = build_sparse_table(weights);

    doub ans;
    ll a1_zapr,a2_zapr;
    
    while (m--)
    {
        cin>>a1_zapr>>a2_zapr;
        ans = get_ans(min(indxs[a1_zapr],indxs[a2_zapr]),max(indxs[a1_zapr],indxs[a2_zapr]),logs,sparce_table);
        cout << eil[ans.ind];
    }
    
}