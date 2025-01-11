#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()

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

struct duo
{
    ll a;
    ll ind;

    bool operator<(const duo &Other) const
    {
        return a < Other.a;
    }
};

bool is_prime(ll n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

string rev(string s, ll l, ll r)
{
    string ans = "";
    for (int i = 0; i < l; i++)
    {
        ans += s[i];
    }
    for (int i = l; i <= r; i++)
    {
        if (s[i] == '0')
        {
            ans += '1';
        }
        else
        {
            ans += '0';
        }
    }
    for (int i = r + 1; i < s.size(); i++)
    {
        ans += s[i];
    }
    return ans;
}

ll get_summ(string s,ll l,ll r){
    ll summ=0;
    for(int i = l-1 ; i <= r-1;i++){
        if(s[i]=='1'){
            summ++;
        }
    }
    return summ;
}

int main()
{
    ll n, k, q;
    cin >> n >> k >> q;
    string s;
    cin >> s;
    while (q--)
    {
        string curr_s;
        curr_s = s;
        ll l, r;
        cin >> l >> r;
        ll ans=0;
        if (r - l + 1 >= k)
        {
            for (int i = l-1; i + k <= r; i++)
            {
                if(curr_s[i] == '1'){
                    curr_s = rev(curr_s,i,i+k-1);
                    ans++;
                }
            }
            ll summ = get_summ(curr_s,l,r);
            if(summ==0){

                cout << ans << '\n';
            }
            else{cout << -1 << '\n';}
        }
        else{
            ll summ = get_summ(curr_s,l,r);
            if(summ==0){

                cout << 0 << '\n';
            }
            else{cout << -1 << '\n';}
        }
    }
}