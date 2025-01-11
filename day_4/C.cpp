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
        out << i << ' ';
    }
    return out;
}

int main(){
    ll n,m,l,r;
    cin >> n >> m;
    vector<pair<ll,ll>> pars;
    REP(m){
        cin >> l >> r;
        l--;r--;
        pars.push_back({l,r});
    }
    vector<ll> dp(n,0);
    dp[0]=2;
    for(int i = 1 ; i < n ; i ++){
        ll bad_ans=0;
        for(int j = 0 ; j < i ; j ++){
            bad_ans = max(bad_ans , dp[j]);
        }   

        bool chh=0;
        ll good_ans=0;
        for(auto& ch : pars){
            if(ch.second == i){
                chh=1;
                for(int j = 0 ; j < ch.first;j++){
                    good_ans = max(dp[j],good_ans);
                }
                for(int j = ch.first ; j <= i ; j ++){
                    dp[j] = good_ans+2;
                }
            }
        }
        if(!chh){dp[i] = bad_ans+2;}
    }
    //cout << dp << '\n';
    cout << dp[n-1] << '\n';
}