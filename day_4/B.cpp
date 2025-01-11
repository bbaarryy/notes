#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

#include <bits/stdc++.h>

using namespace std;

#define ll int
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

bool comp(pair<ll,ll> a,pair<ll,ll> b){
    return a.second < b.second;
}

string s,t;
vector<vector<ll>> graph;
bool good=0;

void dfs(ll curr, ll pr,ll ind){
    if(s[curr] == t[ind]){
        ind ++ ;
        if(ind >= t.size()){
            good=1;
            return;
        }
    }
    for(auto& nxt : graph[curr]){
        if(nxt != pr){
            dfs(nxt,curr,ind);
        }
    }
}
ll mxd=0;
ll ans1=0;

vector<ll> dp;

void dfs_2(ll curr,ll pr){
    dp[curr]=1;

    ll mx1=-1,mx2=-1;
    for(auto& nxt : graph[curr]){

        if(nxt != pr){
            dfs_2(nxt,curr);
        }
        if(dp[nxt] >= mx1){
            mx2=mx1;
            mx1=dp[nxt];
        }
        else if(dp[nxt] > mx2){
            mx2 = dp[nxt];
        }
    }
    dp[curr] += mx1 + mx2;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        good=0;
        cin >> s;

        ll qsa =0;
        for(int i = 0 ; i < s.size();i++){
            if(s[i] == 'a'){
                qsa ++ ;
            }
        }

        graph.clear();
        graph.resize(n);
        ll u,v;
        bool chr5=1;
        REP(n-1){
            cin >> u >> v;
            if(u != i+1 || v != i+2){chr5=0;}
            graph[u-1].push_back(v-1);
            graph[v-1].push_back(u-1);
        }

        cin >> t;

        ll qta=0;
        for(int i = 0 ; i < t.size();i++){
            if(t[i] == 'a'){
                qta++;
            }
        }
            
        bool ch=1;
        ll f=0;
        if(qta==t.size() && qsa == s.size()){
            //найдем диаметр дерева
            dp.resize(n);
            dfs_2(0,-1);
            ll dia = dp[0];
            if(t.size() <= dia){
                cout << ":)" << '\n';
            }
            else{cout << ":(" << '\n';}
        }
        else if((t.size() <= 2) && n > 3000){
            for(int j = 0 ; j < s.size();j++){
                if(f < t.size() && s[j] == t[f]){
                    f++;
                }
            }
            if(f == t.size()){cout << ":)" << '\n';}
            else{cout << ":(" << '\n';}
        }
        else if(chr5 && n > 3000){
            for(int j = 0 ; j < s.size();j++){
                if(f < t.size() && s[j] == t[f]){
                    f++;
                }
            }
            if(f == t.size()){cout << ":)" << '\n';}
            else{
                reverse(all(s));
                f=0;
                for(int j = 0 ; j < s.size();j++){
                    if(f < t.size() && s[j] == t[f]){
                        f++;
                    }
                }
                if(f == t.size()){cout << ":)" << '\n';}
                else{
                    cout << ":(" << '\n';}
            }
        }
        else{
            
            for(int i = 0 ;i < n ; i ++){
                dfs(i,-1,0);
                if(good){cout << ":)" << '\n';ch=0;break;}
            }
            if(ch){cout << ":(" << '\n';}
        }
    }
}