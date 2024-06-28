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

// О(n*log(n))
vector<vector<ll>> build_sparse_table(const vector<ll> &arr)
{ // arr - массив , на котором надо построить разреженную таблицу
    ll n = arr.size();
    ll maxpow = ceil(log2(n + 1));                       // 2^{maxpow} > n
    vector<vector<ll>> sparse(maxpow, vector<ll>(n, 0)); // массив, где одно измерение - длина отрезка(степень двойки!), а другое - левая граница
    sparse[0] = arr;
    for (int k = 0; k + 1 < maxpow; k++)
    { // перебор длины - степени двойки
        for (int ind = 0; ind + (1 << k) < n; ind++)
        { // перебор левой границы
            // ind+(1<<k) , чтобы отрезок не вылезал за границы массива
            sparse[k + 1][ind] = min(sparse[k][ind], sparse[k][ind + (1 << k)]); // выбираем минимум из двух половинок - степень двойки уменьшаем на 1
        }
    }
    return sparse;
}

int main()
{

    ll n;
    cin >> n;

    vector<ll> logs(n+1);//предпосчитаем log2 для каждого числа 
    logs[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        //если для i/2 требуется k делений нацело пополам , то для i - k+1. Log2 - это количество делений числа нацело на два, прежде чем оно станет 1
        logs[i] = logs[i >> 1] + 1;
    }

    vector<ll> arr(n);
    cin >> arr;
    vector<vector<ll>> sparce_table = build_sparse_table(arr);
    ll q, l, r;
    cin >> q;
    while (q--)
    {
        cin >> l >> r;
        l--;//т.к. мы всё делаем на полуинтервалах
        ll maxlog = logs[r-l];//считаем такую наибольшую степень двойки, которая меньше r-l
        cout << min(sparce_table[maxlog][l], sparce_table[maxlog][r - (1 << maxlog)]) << '\n';
    }
}