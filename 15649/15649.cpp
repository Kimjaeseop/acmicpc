#include <iostream>

using namespace std;

int N, M;

void func(int depth, int arr[]) {
	/*
	for (int i = 1; i <= N; i++)
		cout << arr[i] << " ";
	cout << endl;
	*/

	if (depth == M) {
		for (int i = 1; i <= N; i++)
			if (arr[i] != 0)
				cout << arr[i] << " ";

		cout << '\n';
	}

	for (int i = 1; i <= N; i++) {
		if (arr[i] == 0) {
			arr[depth+1] = i;
			func(depth+1, arr);
			arr[depth+1] = 0;
		}
	}
}

int main(void)
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		int arr[9] = {0, };
		arr[1] = i;

		func(1, arr);
	}
	
	return 0;
}
