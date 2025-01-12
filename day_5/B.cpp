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

ll fus(ll a,ll  b){
    if(a==-1)return b;
    if(b==-1) return a;

    if(a<b) swap(a,b);
    if(b%10==b){
        return a*10 + b;
    }
    return a*100+b;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    ll n;
    cin >> n;
    
    vector<ll> arr(n);
    cin >> arr;
    if(n==1){cout << arr[0] << '\n';return 0;}
    
    sort(all(arr));

    vector<ll> dp(n);
    dp[0]=arr[0];
    
    vector<ll> links(n,-1);
    vector<ll> free(n,-1);
    free[0]=0;

    for(int i = 1 ; i < n ; i ++){

        ll now_ans = dp[i-1];

        ll best_dop=0;
        ll curr_dop;
        ll l=-1;

        for (int j = 0; j < i; j++){
            if(links[j] == -1){
                curr_dop = fus(arr[j],arr[i])-arr[j];
            }
            else{
                curr_dop = fus(arr[j],arr[i]);
                curr_dop -= fus(arr[j] , arr[links[j]]);
                if(i%2==1){
                    curr_dop += fus(arr[links[j]],arr[free[i-1]]);
                    curr_dop -= arr[free[i-1]];
                }
                else{ curr_dop += arr[links[j]];}
            }

            if(curr_dop > best_dop){
                best_dop = curr_dop;
                l=j;
            }
        }

        dp[i] = best_dop + now_ans;
        if(best_dop != 0){
            if(i%2==0){
                free[i] = links[l];
                links[links[l]]=-1;
            }
            else{
                if(links[l] != -1){
                    links[links[l]] = free[i-1];
                    links[free[i-1]] = links[l];
                }
            }
            links[l] = i;
            links[i] = l;
        }
        else{free[i] = i;}
    }
     
    cout << dp[n-1] << '\n';
}