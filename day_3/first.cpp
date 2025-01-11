#include <bits/stdc++.h>

using namespace std;

#define ll int
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
        out << i << '\n';
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

int main(){
    ll n,m,a;
    cin >> n >> m;
    vector<ll> bugs(n);
    
    cin>>bugs;

    vector<ll> traps(m);
    cin>>traps;

    vector<ll> curr;
    ll bi=0,ti=0;
    vector<ll> ans(n,-1);

    while(bi<bugs.size() || ti<traps.size()){
        if(bi<bugs.size() && (bugs[bi] <= traps[ti] || ti>=traps.size())){
            curr.push_back(bi);
            bi++;
        }
        else if(ti<traps.size()){
            if(curr.size()>0){
                ans[curr.back()]=ti+1;
                curr.pop_back();
            }
            ti++;
        }
    }
    cout << ans << '\n';
}