#include <stdio.h>

int N;
int A[1000000];
int B, C;
long long sum;

int main(void)
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	scanf("%d %d", &B, &C);

	for (int i = 0; i < N; i++) {
		if (A[i] - B > 0) { // 총 감독관이 한 시험장 전부를 커버 가능한 경우
			sum += ((A[i] - B) % C) == 0 ? (A[i] - B) / C : ((A[i] - B) / C) + 1;
		}
	}

	sum += N;

	printf("%lld\n", sum);

	return 0;
} 
