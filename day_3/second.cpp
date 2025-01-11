#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

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

struct duo{
    ll a;
    ll ind;

    bool operator< (const duo& Other)const{
        return a<Other.a;
    }
};

bool is_prime(ll n){
    for(int i = 2 ; i * i <= n ; i ++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

int main(){
    ll t;
    cin >> t;
    vector<ll> primes;
    for(int i = 2 ; i < 550;i++){
        if(is_prime(i)){
            primes.push_back(i);
        }
    }
    //cout << primes;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> arr(n);
        cin >> arr;
        ll l=0,r=1e18;
        
        while(r-l > 1){
            ll curr = (l+r)/2;
            ll good=0;
            for(int i = n-1 ; i >=0;i--){
                ll curr_ans=0;
                ll now = curr;

                while(now>1){
                    now /= primes[i];
                    curr_ans += now;
                }
                if(curr_ans >= arr[i]){
                    good++;
                }
                else{break;}
            }

            if(good == n){
                r=curr;
            }
            else{l=curr;}
        }
        cout << r << '\n';
    }
}