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
		cout << "�ֻ����� �������? (y/n) ";
		cin >> q;
		if (q == 'y') {
			cout << 1 + rand() % 6 << "��(��) ���Դ�!" << endl;
		}
		else if (q == 'n') {
			break;
		}
		else {
			cout << "y�Ǵ� n�� �Է��ϼ���" << endl;
		}
	}

	return 0;
}