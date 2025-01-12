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

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    ll n;
    cin >> n;
    vector<ll> arr(n);
    cin >> arr;
    ll t;cin>>t;
    vector<ll> pref;
    pref.push_back(0);
    for(int i = 0 ; i < n ; i ++){
        if(arr[i]<0){pref.push_back(pref.back()+1);}
        else pref.push_back(pref.back());
    }

    if(t==1){
        ll q;cin >> q;
        while(q--){
            ll l,r;
            cin >> l >> r;l--;r--;
            bool ch=1;

            ll summ=pref[r+1]-pref[l];

            if(arr[l] == 1 && arr[r]==1){cout << 0 << endl;}
            else{cout << 1<< endl;}
        }
    }
}