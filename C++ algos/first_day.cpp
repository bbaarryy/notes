#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <deque>
#include <array>
#include <list>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <cstring>
#include <random>
#include <bitset>
#include <functional>
#include <random>

using namespace std;

#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define REP(a) for (int i = 0; i < a; i++)

template <typename T>
istream &operator>>(istream &in, vector<T> &a)
{
	for (auto &i : a)
		in >> i;
	return in;
}

struct duo {
	ll l;
	ll r;
	bool operator< (duo& Other)const {
		
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(10);

	//ll a, b;
	//cin >> a >> b;
	//if (a == b && a == 1) { cout << 2 << ' ' << 4 << '\n';return 0; }
	//if (a == b && a == 2) { cout << 3 << ' ' << 6 << '\n'; return 0; }
	//if (a == b && a == 3) { cout << 4 << ' ' << 8 << '\n'; return 0; }

	//ll count = b - a;
	//if (count == 0) {
	//	ll c = 2;
	//	ll ans = b / c;
	//	for (ll i = 2; i*i <= ans; i++) {
	//		if (ans%i == 0) {
	//			cout << c << ' ' << i*c <<'\n'; return 0;
	//		}
	//	}
	//	cout << c << ' ' << ans * c << '\n'; return 0;
	//}

	//if (count == 1) { cout << -1 << ' ' << -1 << '\n'; return 0; }
	//vector<ll> delit;
	//delit.push_back(count);
	//for (ll i = 2; i*i <= count; i++) {
	//	if (count%i == 0) {
	//		
	//		delit.push_back(i);
	//		delit.push_back(count/i);
	//		count /= i;
	//	}
	//}
	//sort(all(delit));
	////for (auto& c : delit) { cout << c << ' '; }
	////cout << '\n';
	//for (auto& c : delit) {
	//	ll ost = a % c;
	//	ll new_b = b - ost;
	//	if (new_b / c != 1) { 
	//		ll ans = new_b/c;
	//		for (ll i = 2; i*i <= ans; i++) {
	//			if (ans%i == 0) {
	//				cout << c << ' ' << i*c << '\n'; return 0;
	//			}
	//		}
	//		cout << c << ' ' << new_b << '\n';
	//	return 0; }
	//}
	//cout << -1 << ' ' << -1 << '\n';

	//ll n, k;
	//cin >> n >> k;
	//vector<ll> arr(n); cin >> arr;
	//vector<vector<ll>> dp(n,vector<ll> (n+1,0));
	//ll ans = -1;
	//for (int i= 1; i < n; i++) {
	//	for (int kk = 2; kk <= (i+1); kk++) {
	//		for (int j = 0; j < i; j++) {
	//			dp[i][kk] = max(dp[i][kk] , dp[j][kk - 1] + (arr[i] ^ arr[j]));
	//			//dp[i][kk] = max(dp[i][kk], dp[j][kk]);
	//			if (kk <= k) { ans = max(ans, dp[i][kk]); }
	//		}
	//	}
	//}
	//
	//for (int i = 0; i <= k; i++) {
	//	ans = max(ans, dp[n - 1][i]);
	//}
	//cout << ans;

	ll n,l,r;
	cin >> n;
	vector<ld> arr(n);
	cin >> arr;
	ll q;
	cin >> q;
	vector<ll> numbers(n,0);
	vector<duo> qs;
	while (q--) {
		cin >> l >> r;
		qs.push_back({l-1,r-1});
	}

	vector<ll> pows(60);
	pows[0] = 1;
	for (int i = 1; i < 60; i++) {
		pows[i] = pows[i - 1] * 2;
	}
	cin >> l >> r;
	l--; r--;
	ll one, two, three;
	one = ones[r+1] - ones[l];
	two = twos[r+1] - twos[l];
	three = threes[r + 1] - threes[l];
	ld ans = 0;
	if (one != 0) {
		ans = 1.00000;
		if(two>0) ans = (ans + pows[min((ll)59, two)] * 2 - 2) / (pows[min((ll)59, two)]);
		if(three>0) ans = (ans + pows[min((ll)59, three)] * 3 - 3) / (pows[min((ll)59, three)]);
	}
	else if (two != 0) {
		ans = 2;
		two -= 2;
		if (two > 0) ans = (ans + pows[min((ll)59, two)] * 2 - 2) / (pows[min((ll)59, two)]);
		if (three > 0) ans = (ans + pows[min((ll)59, three)] * 3 - 3) / (pows[min((ll)59, three)]);
	}
	else if (three != 0) {
		ans = 3;
		three -= 2;
		if (three > 0) ans = (ans + pows[min((ll)59, three)] * 3 - 3) / (pows[min((ll)59, three)]);
	}
	cout << fixed << ans << '\n';

	

}
