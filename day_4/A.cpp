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

bool is_in(ll ost,ll l,ll r,ll dell){
    ost = (l/dell)*dell + ost;
    if(ost >= l && ost <=r){
        return 1;
    }
    ost +=dell;
    if(ost >= l && ost <=r){
        return 1;
    }
    return 0;
}

int main(){
    ll n,a,b;
    cin >> n;
    vector<pair<ll,ll>> arr;
    for(int i = 0 ; i < n ; i ++){
        cin >> a >> b;
        arr.push_back({a,b});
    }
    ll t;
    cin >> t;
    while(t--){
        ll l,r,k;
        cin >> l >> r >> k;
        ll money=0;
            ll day=0;
        while(k--){

            ll minimum = 1e9;
            for(int i = l-1 ; i < r ; i ++){
                minimum = min(minimum , arr[i].first + day*arr[i].second);
                
            }
            day++;
            money = minimum;
        }
        cout << money << '\n';
    }
}