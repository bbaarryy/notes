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

void insert(vector<doub>& arr, doub& new_num) {//добавление нового элемента
	if (arr.size() == 0) {
		arr.push_back(new_num);
	}
	else {
		arr.push_back(new_num);
		int ind = arr.size() - 1;
		// ищем место для нового элемента в структуре
		// элемент «всплывает» пока он меньше очередного родителя

		while (ind >= 0) {
			int par_ind = (ind - 1) / 2;
			if (par_ind >= 0 && arr[ind] < arr[par_ind]) {
				swap(arr[ind], arr[par_ind]);
				ind = par_ind;
			}
			else break;
		}
	}
}

void deleteNode(vector<doub>& array) {
	swap(array[0], array[array.size() - 1]);//Меняем вершину коорую нужно удалить(т.е. корень) с конечным элементом
	array.pop_back();
	ll ind = 0;
	// ищем «правильное» место в структуре для элемента,
	// находящегося на вершине кучи,
	// элемент «топится» пока он больше очередного потомка
	// повторяем пока индекс элемента i меньше размера массива
	while (ind < array.size()) {
		ll child = ind * 2 + 1;
		// индекс правого потомка child+1
		// должен быть меньше размера массива
		// если значение правого потомка меньше левого,
		// то перемещаем индекс на правого потомка
		if (child + 1 < array.size() && array[child + 1] < array[child]) { child++; }
		if (child < array.size() && array[child] < array[ind]) {
			swap(array[child], array[ind]);
			ind = child;
		}
		else { break; }
	}
}



int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<ll> arr;
	ll n, o; cin >> n;
	REP(n) { cin >> o; insert(arr, o); }
	cout << arr;
	cin >> n;
	REP(n) { deleteNode(arr); }
	cout << arr;
}
