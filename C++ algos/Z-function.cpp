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

void print_array_ll(vector<ll>& a) {
	for (auto i : a) {
		cout << i << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	//z-функция
	vector<ll> z(n,0);
	ll l=0, r=0;//-границы текущего суффикса 
	for (int i = 1; i < n; i++) {
		int curr_len_of_suff;
		if (i > r) {
			curr_len_of_suff = 0;
		}
		else {
			curr_len_of_suff = min(z[i - l], r - i + 1);//у I-го символа будет точно хотя бы тот же суффикс , что 
			//и у относительно такого же элемента в суффиксе с начала , но не больше границы суффикса
		}
		while ((i + curr_len_of_suff < n) && s[curr_len_of_suff] == s[i + curr_len_of_suff]) { //далее проверяем , можно ли добавить еще элементов
			curr_len_of_suff++;
		}
		if (i + curr_len_of_suff - 1 > r) {
			r = i + curr_len_of_suff - 1; l = i;
		}
		z[i] = curr_len_of_suff;
	}
	print_array_ll(z);
}