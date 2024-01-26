#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>>mp;
vector<vector<int>>visited[2]; //[부순상태][x][y]
const int INF = 9000000;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int bfs() {
	queue<tuple<int, int, int>>q;
	visited[0][0][0] = 1;
	q.push({ 0,0,0 });
	while (!q.empty()) {
		int broke, x, y;
		tie(broke, x, y) = q.front();
		if (x == n - 1 && y == m - 1) {
			//부쉈든 안부쉈든, 최초 도달하면 그때가 최단거리임
			return visited[broke][x][y];
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nd = visited[broke][x][y] + 1;
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
			if (broke) {
				//더이상 못뿌심
				if (mp[nx][ny] == 1 || visited[1][nx][ny])continue;
				visited[1][nx][ny] = nd;
				q.push(make_tuple(1, nx, ny));
			}
			else {
				if (visited[0][nx][ny])continue;
				if (mp[nx][ny] == 1) {
					//아직 안부쉈으니까 부숴본다
					visited[1][nx][ny] = nd;
					q.push(make_tuple(1, nx, ny));
				}
				else {
					//벽 아니므로 그냥 ㄱㄱ
					visited[0][nx][ny] = nd;
					q.push(make_tuple(0, nx, ny));
				}

			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	mp.assign(n, vector<int>(m));
	visited[0].assign(n, vector<int>(m)); //벽 안뿌신 상태
	visited[1].assign(n, vector<int>(m)); //벽 뿌심
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j  < m; j ++) {
			mp[i][j] = str[j] - '0';
		}
	}
	//입력끝
	cout<<bfs();
}