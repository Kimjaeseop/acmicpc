#include <iostream>

using namespace std;

int N;
int cnt;
int arr[500001];

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < N; i++) 
		for (int j = i + 1; j < N; j++) 
			if (arr[i] > arr[j])
				cnt++;

	cout << cnt << endl;
	
	return 0;
}
