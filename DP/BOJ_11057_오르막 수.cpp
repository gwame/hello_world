#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1001][10];
const int d = 10007;
int ans = 0;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (i == 1) {
				dp[i][j] = 1;
				continue;
			}
			for (int k = 0; k <= j; k++) {
				dp[i][j] = (dp[i][j] + dp[i - 1][k]) % d;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		ans = (ans + dp[n][i]) % d;
	}
	cout << ans;
}