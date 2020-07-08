#include <stdio.h>

#define M 40

int dp[41][2];

int T, N;

int main(void)
{
	scanf("%d", &T);

	dp[0][1] = dp[1][0] = 0;
	dp[0][0] = dp[1][1] = 1;

	for (int i = 2; i <= M; i++) {
		dp[i][0] = dp[i-1][0] + dp[i-2][0];
		dp[i][1] = dp[i-1][1] + dp[i-2][1];
	}

	for (int i = 0; i < T; i++) {
		scanf("%d", &N);

		printf("%d %d\n", dp[N][0], dp[N][1]);
	}

	return 0;
}
