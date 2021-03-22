#include <iostream>
#include <unistd.h>

using namespace std;

int N;
bool arr[4096][6145]; // width는 N*2-1이므로 3*2^10 * 2의 크기가 필요하다

void func(int y, int x, int size) {
	if (size == 3) {
		arr[y][x + 2] = true;
		arr[y + 1][x + 1] = true; arr[y + 1][x + 3] = true;

		for (int i = 0; i < 5; i++)
			arr[y + 2][x + i] = true;

		return ;
	}

	// (size * 6) / 3
	int width = size * 2; // 24 -> 48

	func(y, x + (width/2/2), size/2);
	func(y + (size/2), x, size/2); func(y + (size/2), x + width / 2, size/2);
	
}

int main(void)
{
	cin >> N;

	func(1, 1, N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N*2-1; j++) {
			if (arr[i][j] == true)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
	
	return 0;
}
