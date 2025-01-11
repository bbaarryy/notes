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

    struct duo{
        ll who;
        ll count;
    };

    vector<duo> wins;
    vector<vector<ll>> graph;
    vector<bool> used;

    void dfs(ll me,ll curr,ll turn){
        used[curr]=1;
        if(wins[curr].count > turn){
            wins[curr].who = me;
            wins[curr].count = turn;
        }
        for(auto nxt : graph[curr]){
            if(!used[nxt]){
                dfs(me,nxt,turn+1);
            }
        }
    }

    int main()
    {
        ll n,q,a,b;
        cin >> n >> q;
        graph.resize(n);
        for(int y = 1 ; y < n ; y ++){
            ll a,b;
            cin >> a >> b;
            graph[a-1].push_back(b-1);
            graph[b-1].push_back(a-1);
        }
        while(q--){
            ll k;
            cin >> k;
            ll cr;
            used.clear();
            used.resize(n);

            wins.clear();
            wins.resize(n);
            for(int i = 0 ; i < k ; i ++){
                cin >> cr;
                dfs(i,cr,0);
            }
            ll ans=0;
            for(auto ch : wins){
                if(ch.who==0){
                    ans++;
                }
            }
            cout << ans << '\n';
        }
    }