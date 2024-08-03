#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) a.begin(),a.end()

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

int main(){
    //НВП
    ll n;
    cin >> n;
    vector<ll> arr(n);
    cin >> arr;
    vector<ll> dp(n,1e9);//dp[i] - последний элемент , на который оканчивается НВП длиной i 
    vector<ll> dp_pr(n,-1);//это для восстановления ответа
    vector<ll> arr_pr(n,-1);
    dp[0]=-1e9;
    ll finish=-1;
    for(int i = 0 ; i < n ; i ++){
        auto it = upper_bound(all(dp),arr[i]);//ищем элемент dp[j], который больше arr[i] , но dp[j-1] < arr[i] , чтобы обновить его
        ll ind = it - dp.begin();
        if(dp[ind-1] < arr[i] && dp[ind] > arr[i]){
            finish= max(finish , ind);
            dp[ind] = arr[i];
            dp_pr[ind] = i;
            arr_pr[i] = dp_pr[ind-1];
        }
    }
    
    ll curr=dp_pr[finish];
    vector<ll> ans_v;
    while(finish--){
        ans_v.push_back(arr[curr]);
        curr = arr_pr[curr];
    }
    reverse(all(ans_v));
    cout << ans_v;
}