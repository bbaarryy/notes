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
		out << i << "  ";
	}
	return out;
}

ll gcd(ll a, ll b)
{
	if (b == 0)
		return a;
	a %= b;
	return gcd(b, a);
}

bitset<6250000> dp;//массив , где хранятся только 0 или 1 , именно биты , поэтому в 64 раза быстрее

int main() {

	ll n, w;
	cin >> n >> w;
	vector<ll> arr(n);
	cin >> arr;

	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		dp = dp | (dp << arr[i]);
	}
	if (dp[w]) {
		cout << "YES" << '\n';
	}
	else { cout << "NO" << '\n'; }
}

