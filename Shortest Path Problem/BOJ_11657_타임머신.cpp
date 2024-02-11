#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct Edge {
	int src, dst;
	ll weight;
	Edge(int s, int d, ll w) : src(s), dst(d), weight(w) {}
};

int n, m;
const ll INF = 9'999'999'999;
vector<ll>dist;
vector<Edge>edges;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	dist.assign(n + 1, INF);
	int a, b;
	ll c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		edges.push_back(Edge(a, b, c));
	}
	//입력끝
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
	//출력
	for (int i = 2; i <= n; i++) {
		cout << (dist[i] == INF ? -1 : dist[i]) << '\n';
	}
}