#include <iostream>
#include <math.h>

using namespace std;

// 시작 끝 값에 또 다시 주의 ..
// 0 9 0 1 2 3 4 5 6 7 9 // answer = 9, result = 1 // 0에 대한 처리가 완벽하지 않았음

int N, M, arr[10];

bool check(int n)
{
	if (n == 0) {
		return !arr[0];
	}

	while (n > 0) {
		if(arr[n % 10])
			return false;

		n /= 10;
	}

	return true;
}

int digit(int n)
{
	int count = 0;

	if (n == 0)
		return 1;

	while (n > 0) {
		n /= 10;
		count++;
	}

	return count;
}

unsigned int ABS(int n)
{
	return n > 0 ? n : (n * -1);
}

int main(void)
{
	int tmp;
	int MIN;

	//freopen("input_3.txt", "r", stdin);

	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		scanf("%d", &tmp);

		arr[tmp] = 1;
	}

	MIN = ABS(N - 100);

	for (int i = 0; i < 1000000; i++) {
		if (check(i) == true) {
			int d = ABS(N - i) + digit(i);

			if (MIN > d) {
				MIN = d;
			}
		}
	}

	printf("%d\n", MIN);

	return 0;
}
