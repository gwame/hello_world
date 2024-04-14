#include <bits/stdc++.h>
using namespace std;

int n, len;
string meow;
vector<pair<char, int>>nyan;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> meow;
	len = meow.length();
	for (int i = 0; i < len;) {
		int j = i+1;
		while (j < len && meow[i] == meow[j]) {
			j++;
		}
		nyan.push_back({ meow[i], j-i });
		i = j;
	}
	len = nyan.size();
	int left = 0;
	int right = 1;
	int ans = nyan[0].second;
	int cur = nyan[0].second;
	map<char, int>cmap;
	cmap.insert({ nyan[0].first, 1 });
	while (right < len) {
		if (cmap.find(nyan[right].first) != cmap.end()) {
			cmap[nyan[right].first]++;
			cur += nyan[right++].second;
		}
		else if (cmap.size() < n) { //more letters
			cmap.insert({ nyan[right].first, 1 });
			cur += nyan[right++].second;
		}
		else { //full
			cmap[nyan[left].first]--;
			if (cmap[nyan[left].first] == 0)cmap.erase(nyan[left].first);
			cur -= nyan[left++].second;
		}
		//cout << "cur: " << cur << '\n';
		ans = (ans < cur) ? cur : ans;
	}
	cout << ans;
}