#include <stdio.h>

// 수는 그 수 이하의 수만 만들 수 있음
// ex ) 8 -> 8 이하의 수가 만들 수 있다.
// dp[i-1][1~8]을 더하면 현재 depth에서의 8의 개수를 알 수 있다.

int dp[1001][10];

int main(void)
{
	int N;
	scanf("%d", &N);

	for (int i=0; i<=9; i++)
		dp[1][i] = 1;

	for (int i=2; i<=N; i++) { // depth (길이)
		for (int j=0; j<=9; j++) { // 기준 숫자 (현재 숫자)를 꺼내서
			for (int p=0; p<=j; p++) { // 기준 숫자보다 작은 수의 개수를 더함
				dp[i][j] += dp[i-1][p];
				dp[i][j] %= 10007;
			}
		}
	}

	int sum=0;

	for (int i=0; i<=9; i++)
		sum += dp[N][i];

	printf("%d\n", sum%10007);

	return 0;
}
