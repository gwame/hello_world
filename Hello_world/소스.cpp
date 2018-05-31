#include<iostream>
#include<ctime>
using namespace std;

int main() {
	int i{ 0 };
	while (i < 5) {
		cout << "hello world!" << endl;
		i++;
	}
	//hello world

	for (int i{ 0 }; i < 5; i++) {
		cout << ":D ";
	}
	char q=' ';
	while (1) {
		cout << "주사위를 굴릴까요? (y/n) ";
		cin >> q;
		if (q == 'y') {
			cout << 1 + rand() % 6 << "이(가) 나왔다!" << endl;
		}
		else if (q == 'n') {
			break;
		}
		else {
			cout << "y또는 n을 입력하세요" << endl;
		}
	}

	return 0;
}