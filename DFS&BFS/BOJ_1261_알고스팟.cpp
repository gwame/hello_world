#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int>Pos;
typedef pair<Pos, int>BB; //{위치, 벽뿌순횟수}
int n, m;
vector<vector<int>>maze;
vector<vector<int>>visited;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int ans = 999'999'999;

bool isValid(Pos p) {
	return p.first >= 0 && p.second >= 0 && p.first < n && p.second < m;
}

void dfs(BB st) {
	Pos cur = st.first;
	if (cur.first == n - 1 && cur.second == m - 1) {
		ans = (ans > st.second ? st.second : ans);
		return;
	}
	for (int i = 0; i < 4; i++) {
		Pos nxt = { cur.first + dx[i], cur.second + dy[i] };
		if (!isValid(nxt))continue;
		//여태까지 뿌순횟수에 다음칸 벽유무를 더하자
		int bCnt = st.second + maze[nxt.first][nxt.second];
		if (visited[nxt.first][nxt.second] <= bCnt)continue;
		visited[nxt.first][nxt.second] = bCnt;
		dfs({ nxt, bCnt });
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n;
	maze.assign(n, vector<int>(m));
	visited.assign(n, vector<int>(m, 999'999)); //해당칸에 벽 몇개뿌수고 도착했는지
	string row;
	for (int i = 0; i < n; i++) {
		cin >> row;
		for (int j = 0; j < m; j++) {
			maze[i][j] = row[j] - '0';
		}
	}
	visited[0][0] = 0;
	dfs({ {0,0},0 });
	cout << ans;
}