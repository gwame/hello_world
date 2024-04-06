#include <bits/stdc++.h>
using namespace std;

typedef pair<int, string>Stt;
int t;

int regCalc(char c, int x) {
	int d1 = x / 1000;
	int d4 = x % 10;
	switch (c) {
	case 'D':
		x = (x + x) % 10000;
		break;
	case 'S':
		x = (x == 0 ? 9999 : x - 1);
		break;
	case 'L':
		x = (x * 10) % 10000;
		x += d1;
		break;
	case 'R':
		x = (x / 10) % 1000;
		x += d4 * 1000;
		break;
	default:
		break;
	}
	return x;
}
/*
int LRotateCnt(int a, int b) {
	//a�� L���길���� b�� ���� �� �ִٸ� �� Ƚ�� ��ȯ. R������ (4-��ȯ��)�̹Ƿ� �ּҰ��� �����޼��忡�� ��缱��.
	//�Ұ����ϸ� -1 ��ȯ
	if (a == b)return 0;
	for (int i = 1; i <= 3; i++) {
		a = regCalc('L', a);
		if (a == b)return i;
	}
	return -1;
}
*/
int subCnt(int a, int b) {
	//a�� S������ �� �� �ؾ� b�� ���� �� �ֳ�
	return a - b + (a < b ? 10000 : 0);
}
bool validRotate(int a) {
	//4�ڸ� ��ΰ����� L, R ���ǹ�
	return !(a / 1000 == (a / 100) % 10 && a / 1000 == (a / 10) % 10 && a / 1000 == a % 10);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	int a, b;
	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		vector<int>visited(10000);
		queue<Stt>q;
		q.push({ a, "" });
		string ans = "";
		visited[a] = true;
		int atMost = subCnt(a, b); //'S'�� �ݺ��ϴ� �ͺ��� ������� ��
		while (!q.empty()) {
			int cur = q.front().first;
			string h = q.front().second;
			q.pop();
			//cout << h << " res: " << cur << '\n';
			if (h.length() > atMost)continue;
			if (cur == b) {
				ans = h;
				break;
			}
			int dcur = regCalc('D', cur);
			int scur = regCalc('S', cur);
			int lcur = regCalc('L', cur);
			int rcur = regCalc('R', cur);
			if (cur != 0 && !visited[dcur]) {
				visited[dcur] = true;
				q.push({ dcur, h + "D" });
			}
			if (!visited[scur]) {
				visited[scur] = true;
				q.push({ scur, h + "S" });
			}
			if (validRotate(cur)) {
				if (!visited[lcur]) {
					visited[lcur] = true;
					q.push({ lcur, h + "L" });
				}
				if (!visited[rcur]) {
					visited[rcur] = true;
					q.push({ rcur, h + "R" });
				}
			}
		}
		cout << ans << '\n';
	}
}