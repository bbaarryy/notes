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

	ll n, h,l,r;
	ld wire;
	
	cin >> n >> wire >> h;
	//if (wire == 0) { cout << "bebe"; return 0; }
	//if (h == 0) { cout << "bebe"; return 0; }
	vector<bool> holes(n,0);
	vector<bool> reverse_holes(n, 0);

	REP(h) {
		cin >> l;
		holes[l-1]=1;
		reverse_holes[n - (l - 1) - 1] = 1;
	}

	vector<v> dots;
	REP(n) {
		cin >> l >> r;
		dots.push_back({l,r});
	}
	for (int i = 0; i < n; i++) {
		if (holes[i] == 1) {
			all_hp += dist(dots[i],dots[(i+1)%n]);
		}
	}

	if (wire == 0) { cout <<fixed << all_hp; return 0; }
	ld first_ans = solve(dots, holes, n, wire);
	dots.push_back(dots[0]);
	reverse(all(dots));
	dots.pop_back();
	ld second_ans = solve(dots,reverse_holes,n,wire);
	//cout << solve(dots,holes,n,wire,h);

	cout << fixed << min(first_ans,second_ans);
}
