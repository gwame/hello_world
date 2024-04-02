# DFS & BFS
방문체크 까먹지말기  
visited를 별도로 만드는 대신 정점에 상태값을 기입해서 다른 작업도 할 수 있음  
|비교|DFS|BFS|
|---|---|---|
|탐색 방식|깊이우선|너비우선|
|구현|주로 재귀, 가끔 스택&nbsp;|큐|
|최단경로 구할땐?|DFS보다|BFS가 좋음|
|메모리|덜씀|수평한(동일depth) 정점 큐에 넣느라 메모리를 쓴다|
## 문제 리스트
|문제|&nbsp;&nbsp;코드&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;풀이&nbsp;&nbsp;&nbsp;&nbsp;|
|:---|:---:|:---:|
|[영역 구하기](https://www.acmicpc.net/problem/2583)&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|[</>](./BOJ_2583_영역%20구하기.cpp)| [➡️](#boj-2583-영역-구하기)|
|[벽 부수고 이동하기](https://www.acmicpc.net/problem/2206)&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|[</>](./BOJ_2206_벽%20부수고%20이동하기.cpp)| [➡️](#boj-2206-벽뿌이)|
|[알고스팟](https://www.acmicpc.net/problem/1261)&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|[</>](./BOJ_1261_알고스팟.cpp)| [➡️](#boj-1261-알고스팟)|
## 문제 상세
#### BOJ 2583 영역 구하기
구분되는 영역 개수와 각각의 면적 구하기  

유사 문제: [단지번호붙이기](https://www.acmicpc.net/problem/2667), [유기농 배추](https://www.acmicpc.net/problem/1012)

```cpp
for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
        //매 미방문 칸마다 BFS
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
            for (int l = 0; l < 4; l++) { //인접 4칸
                int nx = x + dx[l];
                int ny = y + dy[l];
                if (nx < 0 || nx >= m || ny<0 || ny>=n)continue;
                if (mn[nx][ny] > 0)continue;
                mn[nx][ny] = 2; //방문체크
                q.push({ nx,ny });
            }
        }
        //이번 칸에서 BFS 끝
        ans.push_back(area);
    }
}
```

#### BOJ 2206 벽뿌이
n, m이 up to 1000이므로 모든 벽 하나하나마다 부숴보고 BFS돌리면 시간초과  
3차원 visited 배열을 만들어서 0 layer는 벽 미파괴상태, 1 layer는 파괴한 상태로 체크해야함  
0 → 0, 0 → 1, 1 → 1은 가능하지만 1 → 0은 불가
```cpp
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
```

#### BOJ 1261 알고스팟
방문처리에 벽뿌순횟수를 카운트한다는 발상까지는 좋았지만 최단거리 문제임에도 불구하고 BFS가 아니라 DFS로 푼 결과 684ms라는 수행시간이 찍혔다! 다른 C++코드는 거의 0~4ms 수준이던데...😕  
왜 그런 선택을 했을까? BFS를 안 떠올린건 아니지만 벽의 존재로 인해 $(N, M)$칸에 최초로 도착했을 때가 최소 벽파괴를 보장하진 않을 거라고 생각했었다. 그래서 'DFS 주루룩 돌리고 `visited[N][M]` 최솟값 가져오면 되겠지?' 라는 나이브한 선택을 했던 것이다   
BFS에 deque를 사용한 풀이에서는 빈칸이면 큐의 맨 앞에, 벽칸이면 맨 뒤에 삽입하도록 구현한 것을 보았다. **벽 덜뿌시고 도착하기**가 목적이니까 이렇게 우선순위 높은 행동은 deque로 새치기시키면 된다는 묘수가 있었다😯