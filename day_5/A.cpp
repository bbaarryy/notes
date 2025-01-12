#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

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
        out << i << '\n';
    }
    return out;
}

struct duo{
    ll h,c;
};

bool comp(duo& a,duo& b){
    return a.h < b.h;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    ll n,curr_h,curr_c,all_c=0;
    cin >> n;
    vector<duo> arr(n+1);
    arr[0] = {0,0};
    for(int i = 1 ; i <= n ; i ++){
        cin >> arr[i].h;
    }
    for(int i = 1 ; i <= n ; i ++){
        cin >> arr[i].c;
    }
    sort(all(arr),comp);

    ll sloi =0;
    for(int i = 0 ; i <= n ; i ++){
        sloi += arr[i].c;
        all_c += arr[i].c * arr[i].h;
    }
    curr_c = all_c;
    ll dop=0;

    ll ans=all_c;
    ll bans = 0;

    for(ll ind = 1; ind <= n ; ind++){
        curr_c = curr_c - sloi * (arr[ind].h - arr[ind-1].h) + dop*(arr[ind].h - arr[ind-1].h)*2;
        if(curr_c < ans){
            ans = curr_c;
            bans = arr[ind].h;
        }
        dop += arr[ind].c;
    }

    cout << bans << ' ' << ans << '\n';
}