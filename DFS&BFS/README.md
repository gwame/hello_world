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