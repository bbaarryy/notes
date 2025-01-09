//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

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

struct trio {
	ll last_i;
	ll count;
	ll ans;
};

struct v {
	ll x;
	ll y;
};

ld dist(v a, v b) {
	return (sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y)));
}

ld all_hp = 0.0000000;

ld solve(vector<v> dots,vector<bool> holes,ll n,ld wire) {
	vector<ld> pref_holes;
	vector<ld> pref_all;
	pref_holes.push_back(0);
	pref_all.push_back(0);


	for (int i = 0; i <= 2*n; i++) {
		if (holes[i%n]) {
			pref_holes.push_back(pref_holes.back() + dist(dots[i%n],dots[(i+1)%n]));
		}
		else {
			
			pref_holes.push_back(pref_holes.back());
		}
		pref_all.push_back(pref_all.back() + dist(dots[i%n],dots[(i+1)%n]));
	}


	ll l = 0, r = n;
	ld minimum = 1e18;
	for (int i = 0; i < n; i++) {
		l = 0; r = n;
		while (r - l > 1) {
			ll m = (r + l) / 2;
			if (pref_all[m+i]-pref_all[i] <= wire) {
				l = m;
			}
			else {
				r = m;
			}
		}
		//check r
		if (pref_all[i+r]-pref_all[i] <= wire) { l = r; }

		ld curr_ans = pref_holes[l+i]-pref_holes[i];
		if (wire > pref_all[l+i]-pref_all[i] && holes[(l+i)%n]) {
			curr_ans += wire - (pref_all[l+i]-pref_all[i]);
		}
		minimum = max((ld)0, min(minimum, all_hp - curr_ans));
	}
	minimum = max((ld)0, minimum);
	return minimum;
}

vector<vector<ll>> arr;
vector<vector<bool>> used;
ll summ = 0;

void dfs(ll x,ll y,ll f,ll s,ll n,ll m) {
	summ++;
	used[x][y] = 1;
	if (x + 1 < n && ((arr[x+1][y]==f|| arr[x + 1][y] == s) && used[x+1][y]==0)) {
		dfs(x+1,y,f,s,n,m);
	}
	if (x - 1 >= 0 && ((arr[x - 1][y] == f || arr[x - 1][y] == s) && used[x - 1][y] == 0)) {
		dfs(x - 1, y, f, s, n, m);
	}
	if (y + 1 < m && ((arr[x][y+1] == f || arr[x][y+1] == s) && used[x][y+1] == 0)) {
		dfs(x, y+1, f, s, n, m);
	}
	if (y - 1 >= 0 &&( (arr[x][y-1] == f || arr[x][y-1] == s) && used[x][y-1] == 0)) {
		dfs(x, y-1, f, s, n, m);
	}
}

void fun(pair<ll,ll> a,pair<ll,ll> b) {
	if (max(a.first, b.first) >= min(a.second, b.second)) {
		return 0;
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(10);
	//string s_d,s;
	////cin >> s;
	//getline(cin, s_d);
	//for (int i = 0; i < s_d.size(); i++) {
	//	if (s_d[i] != ' ') {
	//		s += s_d[i];
	//	}
	//}
	////cout << s << '\n';
	//vector<trio> arr(26,{-1,0,0});
	//ll tot_ans = 0,curr_ans;

	//for (int i = 0; i < s.size(); i++) {
	//	ll curr = s[i] - 'a';
	//	if (arr[curr].last_i == -1) {
	//		arr[curr].last_i = i;
	//		arr[curr].count = 1;
	//	}
	//	else {
	//		if (arr[curr].count == 1) { curr_ans = i - 1 - arr[curr].last_i; }
	//		else { curr_ans = arr[curr].ans + (i - 1 - arr[curr].last_i)*arr[curr].count + (arr[curr].count-1); }
	//		tot_ans += curr_ans;
	//		arr[curr].ans = curr_ans;
	//		arr[curr].count++;
	//		arr[curr].last_i = i;
	//	}
	//}
	//cout << tot_ans << '\n';

	//ll n, h,l,r;
	//ld wire;
	//
	//cin >> n >> wire >> h;
	////if (wire == 0) { cout << "bebe"; return 0; }
	////if (h == 0) { cout << "bebe"; return 0; }
	//vector<bool> holes(n,0);
	//vector<bool> reverse_holes(n, 0);

	//REP(h) {
	//	cin >> l;
	//	holes[l-1]=1;
	//	reverse_holes[n - (l - 1) - 1] = 1;
	//}

	//vector<v> dots;
	//REP(n) {
	//	cin >> l >> r;
	//	dots.push_back({l,r});
	//}
	//for (int i = 0; i < n; i++) {
	//	if (holes[i] == 1) {
	//		all_hp += dist(dots[i],dots[(i+1)%n]);
	//	}
	//}

	//if (wire == 0) { cout <<fixed << all_hp; return 0; }
	//ld first_ans = solve(dots, holes, n, wire);
	//dots.push_back(dots[0]);
	//reverse(all(dots));
	//dots.pop_back();
	//ld second_ans = solve(dots,reverse_holes,n,wire);
	////cout << solve(dots,holes,n,wire,h);

	//cout << fixed << min(first_ans,second_ans);

	/*ll n, m;
	cin >> n >> m;
	arr.resize(n, vector<ll>(m));
	set<ll> setic;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			cin >> arr[x][y];
			setic.insert(arr[x][y]);
		}
	}
	ll ans = -1;
	ll fa, sa;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ll first_lord = arr[i][j];
			for (ll second_lord : setic) {
				used.assign(n, vector<bool>(m, 0));
				dfs(i,j,first_lord,second_lord,n,m);
				if (summ > ans) { ans = summ; fa = first_lord; sa = second_lord; }
				summ = 0;

			}
		}
	}
	cout << ans << '\n' << fa << ' ' << sa << '\n';*/

	/*ll n,l,r;
	cin >> n;
	vector<pair<ll, ll>> arr;

	REP(n) {
		cin >> l >> r;
		arr.push_back({l,r});
	}
	ll q;
	cin >> q;
	while (q--) {
		ll k;
		cin >> k;
		k--;
		for (r = arr[k].first; r<arr[k].second; r++) {
			for (l = arr[k].first; l < r; l++) {
				for (int i = 0; i < n; i++) {
					if (i != k) {
						
					}
				}
			}
		}
	}*/

	while (true) {
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << fun({ a,b }, {c,d});
	}
}
