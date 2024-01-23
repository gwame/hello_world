#include <bits/stdc++.h>
using namespace std;

int sdk[9][9];
int cnt = 0;
vector<pair<int, int>>blanks;

// 빈 칸 아닌 다른 칸과 겹치는지 체크하는 함수들
bool rowchk(int x, int y) {
	for (int i = 0; i < 9; i++) {
		if (y == i)continue;
		if (sdk[x][i] == sdk[x][y])return false;
	}
	return true;
}

bool colchk(int x, int y) {
	for (int i = 0; i < 9; i++) {
		if (x == i)continue;
		if (sdk[i][y] == sdk[x][y])return false;
	}
	return true;
}

bool boxchk(int x, int y) {
	for (int i = 0; i < 9; i++) {
		if (x == x - x % 3 + i / 3 && y == y - y % 3 + i % 3)continue;
		if (sdk[x - x % 3 + i / 3][y - y % 3 + i % 3] == sdk[x][y])return false;
	}
	return true;
}

void printSDK() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << sdk[i][j] << ' ';
		}
		cout << '\n';
	}
}

void fill(int n) {
	if (n == cnt) {
		//filled all blanks
		printSDK();
		exit(0);
	}
	int x = blanks[n].first;
	int y = blanks[n].second;
	//cout << "fill " << n << " (" << x << ", " << y << ")\n";
	for (int i = 1; i <= 9; i++) {
		sdk[x][y] = i;
		//cout <<"\twith " << i << "\n";
		if (rowchk(x, y) && colchk(x, y) && boxchk(x, y))fill(n + 1);
		sdk[x][y] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sdk[i][j];
			if (sdk[i][j] == 0) {
				blanks.push_back({ i, j });
			}
		}
	}
	//입력끝
	cnt = blanks.size();
	fill(0);
}