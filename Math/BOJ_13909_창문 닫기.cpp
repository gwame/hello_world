#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;

int main() {
	cin >> n;
	ll ans = 0;
	for (ll i = 1; i * i <= n; i++) {
		ans += i * i <= n;
	}
	cout << ans;
}