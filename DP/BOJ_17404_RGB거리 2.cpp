#include <bits/stdc++.h>
using namespace std;

const int INF = 9'999'999;
int t, n;
vector<vector<int>>dp[3];

int main() {
	cin >> n;
	for (int i = 0; i < 3; i++) {
		dp[i].assign(n, vector<int>(3, INF));
	}
	int color[3];
	int ans = INF;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> color[j];
			if (i == 0) {
				dp[j][0][j] = color[j];
			}
		}
		for (int j = 0; j < 3; j++) {
			if (i > 0) {
				for (int k = 0; k < 3; k++) {
					dp[k][i][j] = 
						min(dp[k][i - 1][(j + 1) % 3]+color[j],
							dp[k][i - 1][(j + 2) % 3]+color[j]);
				}
			}
			if (i == n - 1) {
				for (int k = 0; k < 3; k++) {
					if (k == j)continue;
					ans = min(ans, dp[k][i][j]);
				}
			}
		}
	}
	cout << ans;
}