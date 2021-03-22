#include <iostream>

using namespace std;

int N;
bool arr[6561][6561];

void func(int y, int x, int size) {
	if (size == 1) {
		arr[y][x] = true;
		return ;
	}

	func(y, x, size/3);                func(y, x + (size/3), size/3);                func(y, x + (size/3) * 2, size/3);
	func(y + (size/3), x, size/3);                                                   func(y + (size/3), x + (size/3) * 2, size/3);
	func(y + (size/3) * 2, x, size/3); func(y + (size/3) * 2, x + (size/3), size/3); func(y + (size/3) * 2, x + (size/3) * 2, size/3);
}

int main(void)
{
	cin >> N;

	func(0, 0, N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == true)
				cout << "*";
			else
				cout << " ";
		}

		cout << endl;
	}
	
	return 0;
}
