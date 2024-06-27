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
#include <cstdio>
#include <iomanip>

#define ll long long
#define REP(a) for(int i = 0 ; i < a ; i ++)
#define all(a) a.begin() , a.end()

using namespace std;

template<typename T>
istream& operator>> (istream& in, vector<T>& a) {
	for (auto& i : a) in >> i;
	return in;
}

template<typename T>
ostream& operator<< (ostream& out, const vector<T>& a) {
	for (auto& i : a) { out << i << ' '; }
	return out;
}

struct doub {
	ll l, r;
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//FLOID
	ll n, m,a,b,d;
	cin >> n >> m;
	vector<vector<ll>> matrix(n);//граф 
	vector<vector<ll>> distance(n, vector<ll>(n,1e9));//расстояние между веришнами
	REP(m) {
		cin >> a >> b >> d;
		matrix[a - 1].push_back(b-1);
		matrix[b - 1].push_back(a - 1);
		distance[a-1][a-1] = 0;
		distance[b - 1][b - 1] = 0;
		distance[a-1][b-1] = d;
		distance[b-1][a-1] = d;
	}
	//Сложность - O(n^3)!
	for (int k = 0; k < n; k++) {
		for (int u = 0; u < n; u++) {
			for (int v = 0; v < n; v++) {
				distance[v][u] = min(distance[v][u], distance[v][k] + distance[k][u]);
			}
		}
	}

	REP(n) {
		for (int j = 0; j < n; j++) {
			cout << distance[i][j] << ' ';
		}
		cout << '\n';
	}
}