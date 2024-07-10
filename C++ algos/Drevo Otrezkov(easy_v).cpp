//╔═══╗╔═══╗╔═══╗╔═══╗╔╗──╔╗╔═══╗     ╔═══╗╔════╗╔═══╗╔═══╗╔════╗╔╗╔═╗╔═══╗╔╗──╔╗
//╚╗╔╗║║╔══╝║╔═╗║║╔══╝║╚╗╔╝║║╔═╗║     ║╔═╗║║╔╗╔╗║║╔═╗║║╔══╝╚══╗═║║║║╔╝║╔═╗║║╚╗╔╝║
//─║║║║║╚══╗║╚═╝║║╚══╗╚╗║║╔╝║║─║║     ║║─║║╚╝║║╚╝║╚═╝║║╚══╗──╔╝╔╝║╚╝╝─║║─║║╚╗║║╔╝
//─║║║║║╔══╝║╔╗╔╝║╔══╝─║╚╝║─║║─║║     ║║─║║──║║──║╔╗╔╝║╔══╝─╔╝╔╝─║╔╗║─║║─║║─║╚╝║─
//╔╝╚╝║║╚══╗║║║╚╗║╚══╗─╚╗╔╝─║╚═╝║     ║╚═╝║──║║──║║║╚╗║╚══╗╔╝═╚═╗║║║╚╗║╚═╝║─╚╗╔╝─
//╚═══╝╚═══╝╚╝╚═╝╚═══╝──╚╝──╚═══╝     ╚═══╝──╚╝──╚╝╚═╝╚═══╝╚════╝╚╝╚═╝╚═══╝──╚╝──

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
#include <ctime>
#include <bitset>
#include <numeric>

#define ll long long
#define maxn = 1e18;

using namespace std;

vector<ll> arr;
vector<ll> tree;

void build(int rt, int l, int r) {//rt-индекс элемента в ДО l-левая граница "охвата" элемента r-правая граница "охвата" элемента
	if (l == r) {
		tree[rt] = arr[l];//если левая граница совпала с правой - значит это конечный элемент дерева отрезков , то есть элемент массива
		return;
	}
	int t = (l + r) / 2;//вычисляем середину - чтобы можно было пойти на детей
	build(rt * 2 + 1, l, t);//левый предок
	build(rt * 2 + 2, t + 1, r);//правый предок
	tree[rt] = tree[rt * 2 + 1] + tree[rt * 2 + 2];//получаем сумму с детей
}

void update(int rt, int l, int r, int id, int x) {//аналогично build , только прибавляется x - это то , на что мы заменяем , и id-какой элемент заменяем
	if (l == r) {
		tree[rt] = x;//если дошли до дна дерева - то заменяем этот элемент на x
		return;
	}
	int t = (l + r) / 2;
	if (t >= id) {//если элемент , который нужно изменить слева - идем на левого ребенка
		update(rt * 2 + 1, l, t, id, x);
	}
	else {//иначе - на правого
		update(rt * 2 + 2, t + 1, r, id, x);
	}
	tree[rt] = tree[rt * 2 + 1] + tree[rt * 2 + 2];//получаем сумму от изменившихся детей
}

ll get(int rt, int l, int r, int l1, int r1) {
	if (l >= l1 && r <= r1) {//если границы "охвата" данной точки в ДО , лежат внутри границ массива , сумму которого мы хотим узнать , то прибавляем сумму всех точек , за которые отвечает данная точка
		return tree[rt];
	}
	else if (max(l, l1) > min(r, r1)) {//если уже точно границы "охвата" данной точки в ДО , лежат за пределами границ массива(справа или слева) то возвращаем 0
		return 0;
	}
	//и так делаем для детей
	int t = (l + r) / 2;
	int L = get(rt * 2 + 1, l, t, l1, r1);
	int R = get(rt * 2 + 2, t + 1, r, l1, r1);
	//потом просто возвращаем сумму от детей
	return L + R;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, k, check, left, right, ans, now;
	cin >> n >> k;
	arr.resize(n);
	tree.resize(n * 4);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	build(0, 0, n - 1);
	while (k--) {
		cin >> check >> left >> right;
		if (check == 0) {

			ans = get(0, 0, n - 1, left - 1, right - 1);
			cout << ans << '\n';
		}
		else {
			update(0, 0, n - 1, left - 1, right);
		}
	}
}