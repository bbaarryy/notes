#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()
#define REP(x) for(int i = 0 ; i< x; i ++)
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
    out << i;
  }
  return out;
}

struct trio{
  ll ans;ll back;ll summ;
};

bool dd(ll&A,ll&B){return A>B;}

void solve(ll v, vector<ll> &arr)
{
  ll len=0;
  ll minimum=1e16;
  for(int i = 0 ; i < 9 ; i ++){
    len=max(len,v/arr[i]);
    minimum = min(minimum,arr[i]);
  }
  if(len==0){
    cout<<-1<<'\n';
  }else{
    //cout<<len<<'\n';
    ll last=0;
    for(int i = 0 ; i < len;i++){
      for(int o = 8 ; o>= 0 ; o --){
        if(arr[o] + minimum * (len-i-1)+last <= v){
          cout<<o+1;
          last+=arr[o];
        }
      }
    }
  }
}

#ifndef GOOGLETEST_INCLUDE_GTEST_GTEST_H_

int main(int argc, char **argv)
{
  ll v;
  cin >> v;
  vector<ll> arr(9);
  cin >> arr;
  solve(v,arr);
}

#endif
