#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <set>
#include <cmath>
#include <stack>
#include <string>


#define ll long long

using namespace std;


const int N = 2002;


ll a[N][N], y[N], x[N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    cin >> m;

    for (int i = 1; i <= m; i++) {
        cin >> y[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (x[i] == y[j]) {
                a[i][j] = 1 + a[i - 1][j - 1];
            }
            else {
                a[i][j] = max(a[i - 1][j], a[i][j - 1]);
            }
        }
    }
    int i = n, j = m;
    vector<int> array;
    while (i && j) {
        if (x[i] == y[j]) {
            array.push_back(x[i]);
            i--;
            j--;
        }
        else if (a[i - 1][j] == a[i][j]) {
            i--;
        }
        else {
            j--;
        }
    }
    cout << array.size() << '\n';
    for (int i = array.size() - 1; i>= 0; i--) {
        cout << array[i] << ' ';
    }
}