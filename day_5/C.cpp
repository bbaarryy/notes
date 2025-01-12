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

bool cool(ll n,ll k){
    ll lst=-1;
    ll curr=1;
    while(n>0){
        ll num = n%10;
        if(num != lst){
            if(curr >= k){return 1;}
            curr=1;
            lst=num;
        }
        else{curr++;}
        n/=10;
    }
    if(curr >= k){return 1;}
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    ll a,b,k;
    cin >> a >> b>>k;
    ll ans=0;
    for(int i = a ; i <= b ; i ++){
        if(cool(i,k)){ans++;}
    }
    cout << ans << '\n';
}