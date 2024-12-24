ll n;
cin >> n;
vector<bool> is_prime(n+1,true);
is_prime[0] = is_prime[1] = false;
for (ll i = 2; i <= n; i++) {
  if (is_prime[i]) {
    if (i * i <= n) {
      for (ll k = i * i; k <= n; k *= i) {
        is_prime[k] = false;
      }
    }
  }
}
