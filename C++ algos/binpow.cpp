#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <set>	
#include <cmath>
#include <stack>
#include <string>
#include <queue>
#include <chrono>
#include <stdio.h>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <ctime>

#define ll long long
#define ld long double
#define REP(a) for(int i = 0 ; i < a ; i ++)
#define REPX(a) for(int x = 0 ; x < a ; x ++)
#define all(a) a.begin() , a.end()

using namespace std;

template <typename T>
istream& operator>>(istream& in, vector<T>& a)
{
	for (auto& i : a)
		in >> i;
	return in;
}

template <typename T>
ostream& operator<<(ostream& out, const vector<T>& a)
{
	for (auto& i : a)
	{
		out << i << '\n';
	}
	return out;
}

ll bin_pow(ll a, ll n, ll k) {
	ll res = 1;
	for (; n != 0; n >>= 1, a = (ll)a * a % k) {
		if (n & 1) res = (ll)res * a % k;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m, k;
	cin >> n >> m >> k;
	cout << bin_pow(n, m, k);
}
