#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<vector<int>>mn;
vector<int>ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> m >> n >> k; //m이 행개수 n이 열개수
	mn.assign(m, vector<int>(n));
	int x1, y1, x2, y2;
	for (int i = 0; i < k; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int x = x1; x < x2; x++) {
			for (int y = y1; y < y2; y++) {
				mn[y][x] = 1;
			}
		}
	}

	/*
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (mn[i][j])cout << '#';
			else cout << '_';
		}
		cout << '\n';
	}
	*/

	int dx[] = { 1,0,-1,0 };
	int dy[] = { 0,1,0,-1 };

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			//매 칸마다 BFS
			if (mn[i][j] != 0)continue;
			mn[i][j] = 2; //방문체크
			int area = 0;
			queue<pair<int, int>>q;
			q.push({ i,j });
			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				area++;
				for (int l = 0; l < 4; l++) {
					int nx = x + dx[l];
					int ny = y + dy[l];
					if (nx < 0 || nx >= m || ny<0 || ny>=n)continue;
					if (mn[nx][ny] > 0)continue;
					mn[nx][ny] = 2; //방문체크
					q.push({ nx,ny });
				}
			}
			//BFS 끝
			ans.push_back(area);
		}
	}
	cout << ans.size() << '\n';
	sort(ans.begin(), ans.end());
	for (auto i : ans) {
		cout << i << ' ';
	}
}