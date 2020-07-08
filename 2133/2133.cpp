#include <stdio.h>

int N;
int dp[50];

// 꽉 채워지지 않는 경우 고려 X
// EX) N이 홀수인 경우

// --
// |=|

// |=|
// --

// 위와 같이 N=4부터 row에 N/2개를 전부 눕힌 모양으로 고유의 모양이 두 개 생김
int main(void)
{
	scanf("%d", &N);

	dp[0]=1; // 아무 것도 놓지 않는 경우
	dp[2]=3;

	for (int i=4; i<=N; i+=2) {
		dp[i] = dp[i-2]*dp[2];

		for (int j=4; i-j>=0; j+=2)
			dp[i] += dp[i-j]*2; // 2 == 고유모양의 개수
								// EX) N==8
								// N==6 * N==2
								// N==4 * 4의 고유 모양
								// N==8의 고유모양 2개 // dp[0]=1이 필요한 이유
	}

	printf("%d\n", dp[N]);

	return 0;
}
