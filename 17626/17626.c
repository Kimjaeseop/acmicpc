#include <stdio.h>
#define M 224
#define MIN(A, B) (((A) > (B) ? (B) : (A)))

int arr[51000];
int N;

int main(void) {
	scanf("%d", &N);

	for (int i = 0; i <= 50000; i++) {
		arr[i] = arr[i] == 0 ? i : arr[i]; // 1^2를 i번만큼 더 한 횟수

		if (i <= M) { // 50000의 제곱근보다 i가 작다면 제곱한 수에 횟수(1) 대입
			arr[i*i] = 1;
		}

		for (int j = 0; j * j <= i; j++) {
			arr[i] = MIN(arr[i - j*j] + 1, arr[i]); // i - j*j는 임의의 수 + j^2와 같음
		}
	}

	printf("%d\n", arr[N]);

	return 0;
}
