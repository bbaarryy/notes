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
	
	ll n;
	cin >> n;
	string s;
	cin >> s;
	//z-функция
	//z[i] - это наибольший общий префикс строки s и её i-го суффикса
	vector<ll> z(n,0);
	ll l=0, r=0;//-границы уже обработанного отрезка
	for (int i = 1; i < n; i++) {
		int curr_len_of_pref;//длина текущего префикса для индекса i
		if (i > r) {//если индекс не в обработанном поле , то воспользуемся наивным алгоритмом
			curr_len_of_pref = 0;
		}
		else {//если индекс в обработанном поле , то можно воспользоваться уже посчитанными значениями
			curr_len_of_pref = min(z[i - l], r - i + 1);//у i-го символа будет точно хотя бы тот же префикс , что 
			//и у относительно такого же элемента с начала массива , но не больше границы префикса
		}
		while ((i + curr_len_of_pref < n) && s[curr_len_of_pref] == s[i + curr_len_of_pref]) { //далее проверяем , можно ли добавить еще элементов
			//это наивный алгоритм
			curr_len_of_pref++;
		}
		if (i + curr_len_of_pref - 1 > r) {
			r = i + curr_len_of_pref - 1; l = i;
		}
		z[i] = curr_len_of_pref;
	}
	z[0]=n;
	print_array_ll(z);
}