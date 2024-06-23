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

#define ll long long
#define REP(a) for(int i = 0 ; i < a ; i ++)
#define all(a) a.begin() , a.end()

using namespace std;

struct Node {
	vector<int> go;
	bool terminal;
	Node(){
		go.resize(26, -1);
		terminal = 0;
	}
};

vector<Node> trie(1,Node());

void add_str(string& str) {
	ll v = 0;
	for (char ch : str) {
		ll ind = ch - 'a';
		if (trie[v].go[ind] == -1) {
			trie[v].go[ind] = (int) trie.size() ;
			trie.push_back(Node());
		}
		v = trie[v].go[ind];
	}
	trie[v].terminal=1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll q; cin >> q; string curr_str;
	while (q--) {
		cin >> curr_str;
		add_str(curr_str);
	}
}