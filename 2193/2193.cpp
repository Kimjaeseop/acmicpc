#include <stdio.h>

// 이전 단계의 node 개수 --> 현 단계에서 0의 개수
// 이전 단계의 0의 개수 --> 현 단계에서 1의 개수
// 현 단계 --> 이전 단계의 node 개수 + 이전 단계의 0의 개수

int main(void)
{
	int N;
	long long dp[92][2] = {0,}; // 총 개수, 0의 개수

	scanf("%d", &N);

	if (N==1 || N==2) {
		printf("1\n");
		return 0;
	}
	else {
		dp[1][0]=1;
		dp[1][1]=0;

		for (int i=2; i<=N; i++) {
			dp[i][0] = dp[i-1][0]+dp[i-1][1];
			dp[i][1] = dp[i-1][0];
		}
	}

	printf("%lld\n", dp[N][0]); // integer 사용시 overflow

	return 0;
}
