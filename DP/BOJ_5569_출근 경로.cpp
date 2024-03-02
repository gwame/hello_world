#include <bits/stdc++.h>
using namespace std;

int w, h;
const int d = 100000;
int dp[101][101][4]; //ee, en, nn, ne

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> w >> h;
	if (w > h) {
		int tmp = w;
		w = h;
		h = tmp;
	}
	//동쪽 (w-1)회, 북쪽 (h-1)회 이동
	//경우의 수는 (e+n)!/e!n! 이지만, 2연꺾 제한이 있다
	if (w == 2 || h == 2) {
		cout << 2;
		return 0;
	}
	for (int i = 2; i <= h; i++) {	
		dp[2][i][2] = dp[2][i][3] = 1;
	}
	for (int i = 3; i <= w; i++) {
		for (int j = i; j <= h; j++) {
			if (i == j) {
				dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][3]) % d;
				dp[i][j][1] = dp[i - 1][j][2];
				dp[i][j][2] = (dp[i - 1][j][3] + dp[i - 1][j][0]) % d;
				dp[i][j][3] = dp[i - 1][j][2];
			}
			else {
				dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][3]) % d;
				dp[i][j][1] = dp[i][j - 1][0];
				dp[i][j][2] = (dp[i][j - 1][1] + dp[i][j - 1][2]) % d;
				dp[i][j][3] = dp[i - 1][j][2];
			}
			if (i == w && j == h) {
				int ans = 0;
				for (int k = 0; k < 4; k++) {
					ans = (ans + dp[i][j][k]) % d;
				}
				cout << ans;
			}
		}
	}
}