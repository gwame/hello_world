#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
vector<vector<int>>arr;
vector<vector<int>>memo;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	ans = 0;
	arr.assign(n, vector<int>(m));
	memo.assign(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		string str; cin >> str;
		for (int j = 0; j < m; j++) {
			arr[i][j] = str[j] - '0';
			if (arr[i][j] == 0) {
				memo[i][j] = 0;
				continue;
			}
			if (ans == 0)ans = 1;
			if (i == 0 || j == 0) {
				memo[i][j] = arr[i][j];
				continue;
			}
			int dia = memo[i - 1][j - 1];
			int left = memo[i][j - 1];
			int up = memo[i - 1][j];
			memo[i][j] = min({ dia,left,up }) + 1;
			ans = (ans < memo[i][j] ? memo[i][j] : ans);
		}
	}
	//ÀÔ·Â³¡
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << memo[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << ans * ans;
}