#include <iostream>

using namespace std;

bool arr[10001];
int T, N;

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	arr[0] = arr[1] = true;

	for (int i = 2; i < 10001; i++) 
		for (int j = 2; i*j < 10001; j++) 
			arr[i*j] = true;

	cin >> T;

	int a = 0, b = 0;

	while (T--) {
		cin >> N;
		// for (int i = N/2; i <= N; i++) 로 하면 저장해 둘 필요 없이 격차가 큰 쌍부터 출력되는데 이렇게하면 느리다.. 원래 그런건지 테스트케이스에서 그런건지 ..
		for (int i = 2; i <= N/2; i++) 
			if (arr[i] == false && arr[N-i] == false) {
				a = i;
				b = N - i;
				//break;
			}

		cout << a << ' ' << b << '\n';
	}


	return 0;
}


