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
vector<ll> pus;

//это - для массовых операций----------------
void push(ll i) {
	if (pus[i] != 0) {
		pus[i * 2 + 1] += pus[i];
		pus[i * 2 + 2] += pus[i];
		tree[i * 2 + 1] += pus[i];
		tree[i * 2 + 2] += pus[i];
		pus[i] = 0;
	}
}

void build(ll rt, ll l, ll r) {//rt-индекс элемента в ДО l-левая граница "охвата" элемента r-правая граница "охвата" элемента
	if (l == r) {
		tree[rt] = arr[l];//если левая граница совпала с правой - значит это конечный элемент дерева отрезков , то есть элемент массива
		return;
	}
	ll t = (l + r) / 2;//вычисляем середину - чтобы можно было пойти на детей
	build(rt * 2 + 1, l, t);//левый предок
	build(rt * 2 + 2, t + 1, r);//правый предок
	tree[rt] = max(tree[rt * 2 + 1], tree[rt * 2 + 2]);//получаем сумму с детей
}

void update(ll rt, ll l, ll r, ll ql, ll qr, ll x) {//аналогично build , только прибавляется x-то , на что мы заменяем , и id-какой элемент заменяем
	if (ql > r || qr < l) { return; }
	if (ql <= l && r <= qr) {
		pus[rt] += x;
		tree[rt] += x;
		return;
	}
	ll m = (l + r) / 2;
	push(rt);
	update(rt * 2 + 1, l, m, ql, qr, x);
	update(rt * 2 + 2, m + 1, r, ql, qr, x);
	tree[rt] = max(tree[rt * 2 + 1], tree[rt * 2 + 2]);
}

ll get(ll rt, ll l, ll r, ll l1, ll r1) {
	if (l >= l1 && r <= r1) {//если границы "охвата" данной точки в ДО , лежат внутри границ массива , сумму которого мы хотим узнать , то прибавляем сумму всех точек , за которые отвечает данная точка
		return tree[rt];
	}
	else if (max(l, l1) > min(r, r1)) {//если уже точно границы "охвата" данной точки в ДО , лежат за пределами границ массива(справа или слева) то возвращаем 0
		return 0;
	}
	//и так делаем для детей
	ll t = (l + r) / 2;
	push(rt);
	ll L = get(rt * 2 + 1, l, t, l1, r1);
	ll R = get(rt * 2 + 2, t + 1, r, l1, r1);
	//потом просто возвращаем сумму от детей
	return max(L, R);
}
//-------------------------------------------


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, k, check, left, right, ans, now;
	cin >> n >> k;
	arr.resize(n);
	tree.resize(n * 4);
    pus.resize(n*4);
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
            ll x;
            cin>>x;
			update(0, 0, n - 1, left - 1, right-1,x);
		}
	}
}