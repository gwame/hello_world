#include <bits/stdc++.h>
using namespace std;

int n, s;
int cnt = 1;
vector<vector<int>>grp;
vector<pair<int, int>>lr; //방문체크겸 순서기록

void dfs(int k) {
	lr[k].first = cnt++;
	for (int nxt : grp[k]) {
		if (lr[nxt].first)continue;
		dfs(nxt);
	}
	lr[k].second = cnt++;
}

int main() {
	cin >> n;
	grp.assign(n + 1, vector<int>(0));
	lr.assign(n + 1, { 0,0 });
	int v, c;
	for (int i = 0; i < n; i++) {
		cin >> v;
		while (1) {
			cin >> c;
			if (c == -1)break;
			grp[v].push_back(c);
			grp[c].push_back(v);
		}
		sort(grp[v].begin(), grp[v].end());
	}
	cin >> s; //루트 노드
	dfs(s);
	for (int i = 1; i <= n; i++) {
		cout << i << ' ' << lr[i].first << ' ' << lr[i].second << '\n';
	}
}