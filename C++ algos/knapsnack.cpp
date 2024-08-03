#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) a.begin(),a.end()
#define REP(a) for(int i = 0 ; i < a ; i ++)

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
        out << i << "  ";
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

int main(){
    //freopen("out.txt" , "w" , stdout);

    //пусть у нас дан массив весов , вместительность рюкзака - W , то есть сколько веса он может унести
    //нужно получить рюкзак с максимальным весом

    ll n ,w;
    cin >> n >> w;
    vector<ll> arr(n);
    cin >> arr;
    vector<vector<bool>> dp(n+1,vector<bool> (w+1,false));
    //dp[i][j] - это ответ на ситуацию , когда мы рассмотрели первые N элементов в массиве и получили вес j - могла такая ситуация получится , или нет
    dp[0][0] = true;
    for(int i = 1 ; i <= n; i ++){
        for(int j = 0 ; j <= w ; j ++){
            //или мы не берем этот элемент, тогда
            dp[i][j] =  dp[i-1][j];

            //или мы берем текущий n-ый элемент из массива , тогда 
            if(dp[i-1][j-arr[i]] && j-arr[i] >=0){
                dp[i][j] = dp[i-1][j-arr[i]];
            }
        }
    }
    ll mx=-1;
    for(int i = 0 ; i <= w ; i ++){
        if(dp[n][i]){
            mx = i;
        }
    }
    cout << mx;
}