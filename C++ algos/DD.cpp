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
#include <bitset>
#include <random>

#define ll long long
#define ld long double
#define REP(a) for(ll i = 0 ; i < a ; i ++)
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
        out << i << ' ';
    }
    return out;
}

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    a %= b;
    return gcd(b, a);
}

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

struct Node {
    ll key, prior;
    ll GCD;
    Node* l = 0, * r = 0;
    Node(ll _key) { GCD = _key, key = _key, prior = rnd() % 100000; }
};

void upd(Node* curr) {//для обновления любой величины в вершине - здесь конкретно для НОД
    ll left, right;
    if (!curr) {
        left = 1;
    }
    else if (!curr->l && !curr->r) {
        curr->GCD = curr->key;
    }
    else if (!curr->l && curr->r) {
        curr->GCD = gcd(curr->key, curr->r->GCD);
    }
    else if (curr->l && !curr->r) {
        curr->GCD = gcd(curr->key, curr->l->GCD);
    }
    else {
        curr->GCD = gcd(gcd(curr->l->GCD, curr->r->GCD), curr->key);
    }
}

//слияние
Node* merge(Node* l, Node* r) {//Важно - в левом дереве все ключи меньше, чем в правом
    if (!l) return r;
    if (!r) return l;
    if (l->prior > r->prior) {
        l->r = merge(l->r, r);
        upd(l);
        return l;
    }
    else {
        r->l = merge(l, r->l);
        upd(r);
        return r;
    }
}

//разрезание
pair<Node*, Node*> split(Node* curr, ll x) {
    if (!curr) { return { 0,0 }; }
    if (curr->key <= x) {
        pair<Node*, Node*> pr = split(curr->r, x);
        curr->r = pr.first;
        upd(curr);
        return { curr,pr.second };
    }
    else {
        pair<Node*, Node*> pr = split(curr->l, x);
        curr->l = pr.second;
        upd(curr);
        return { pr.first, curr };
    }
}

Node* root = 0;//но это так, пока нет остальных вершин

bool find(Node* v, ll x) {
    if (!v) { return 0; }
    if (v->key == x) { return 1; }

    if (x > v->key) {
        return find(v->r, x);
    }
    else {
        return find(v->l, x);
    }
}

//вставка
void ins(ll x) {
    if (!find(root, x)) {
        pair<Node*, Node*>pr = split(root, x);
        Node* t = new Node(x);
        Node* sc = merge(t, pr.second);
        upd(sc);
        root = merge(pr.first, sc);
        upd(root);
    }
}

//удаление
void del(ll x) {
    if (find(root, x)) {
        pair<Node*, Node*> pr = split(root, x);
        Node* curr = pr.first;
        if (!curr->r) {
            //curr->sz--;
            root = merge(pr.first->l, pr.second);
            upd(root);
        }
        else {
            deque<Node*> q;

            curr = pr.first->r;
            Node* last = pr.first;

            q.push_front(last);
            q.push_front(curr);
            while (curr->r) {
                last = curr;
                curr = curr->r;

                q.push_front(curr);
            }

            last->r = curr->l;
            for (auto i : q) { upd(i); }
            root = merge(pr.first, pr.second);
            upd(root);
        }
    }
}

//поиск следующего мин. числа, большего данного
Node* next(ll x) {
    pair<Node*, Node*> pr = split(root, x);
    Node* curr = pr.second;
    if (!curr) {
        root = merge(pr.first, pr.second);
        return nullptr;
    }
    while (curr->l) {
        curr = curr->l;
    }
    root = merge(pr.first, pr.second);
    return curr;
}

//поиск следующего макс. числа, меньшего данного
Node* prev(ll x) {
    pair<Node*, Node*> pr = split(root, x-1);
    Node* curr = pr.first;
    if (!curr) {
        root = merge(pr.first, pr.second);
        return nullptr;
    }
    while (curr->r) {
        curr = curr->r;
    }
    root = merge(pr.first, pr.second);
    return curr;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string command;
    while (cin >> command) {
        ll a; cin >> a;
        if (command == "insert") {
            ins(a);
        }
        if (command == "delete") {
            del(a);
        }
        if (command == "exists") {
            bool ans = find(root, a);
            if (ans) { cout << "true" << '\n'; }
            else { cout << "false" << '\n'; }
        }
        if (command == "next") {
            Node* ans_n = next(a);
            if (ans_n)cout << ans_n->key << '\n';
            else cout << "none" << '\n';
        }
        if (command == "prev") {
            Node* ans_n = prev(a);
            if (ans_n)cout << ans_n->key<< '\n';
            else cout << "none" << '\n';
        }
    }
}
