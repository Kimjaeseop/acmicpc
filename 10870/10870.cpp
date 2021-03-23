#include <iostream>

using namespace std;

int arr[21];
int N;

int main(void)
{
	arr[0] = 0; arr[1] = 1;

	cin >> N;

	for (int i = 2; i <= 20; i++)
		arr[i] = arr[i-1] + arr[i-2];

	cout << arr[N] << endl;

	return 0;
}
