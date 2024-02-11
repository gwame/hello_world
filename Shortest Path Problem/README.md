# Shortest Path Problem
- 다익스트라: 사이클리스 논네거티브 유향 트리
- 벨만 포드: 음의 가중치 있을 때
- 플로이드 워셜: n대 n(모든 노드) 최단경로

## 문제 리스트
|문제|&nbsp;&nbsp;코드&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;풀이&nbsp;&nbsp;&nbsp;&nbsp;|
|:---|:---:|:---:|
|[타임머신](https://www.acmicpc.net/problem/11657)&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|[</>](./BOJ_11657_타임머신.cpp)| [➡️](#boj-11657-타임머신)|

## 문제 상세
#### BOJ 11657 타임머신

벨만 포드 기본  
INF로 초기화된 거리배열을 간선리스트를 순회하며 업데이트  
이후 한번 더 for문 돌면서 갱신되는 케이스가 있으면 음수 사이클로 판정

```CPP
dist[1] = 0;
for (int i = 1; i <= n; i++) {
	for (int j = 0; j < m; j++) {
		if (dist[edges[j].src] == INF)continue;
		int nw = dist[edges[j].src] + edges[j].weight;
		dist[edges[j].dst] = (dist[edges[j].dst] > nw) ? nw : dist[edges[j].dst];
	}
}
//음수 사이클 체크
for (int i = 0; i < m; i++) {
	if (dist[edges[i].src] == INF)continue;
	if (dist[edges[i].dst] > dist[edges[i].src] + edges[i].weight) {
		cout << -1;
		return 0;
	}
}
```