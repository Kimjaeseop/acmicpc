#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void)
{
	int N;
	int in[10001]={0,};
	int dp[10001][3]={0,};
	int ans=0;

	scanf("%d", &N);

	for (int i=1; i<=N; i++)
		scanf("%d", &in[i]);

	// dp[x][0] : 0잔 연속 (현재 위치 잔을 마시지 않음)
	// dp[x][1] : 1잔 연속 (이전의 잔을 마시지 않고 현재 잔을 마심)
	// dp[x][2] : 2잔 연속 (이전의 잔을 마셨고 현재 잔들 마심)
	dp[1][0] = 0;
	dp[1][1] = in[1];

	dp[2][0] = in[1];
	dp[2][1] = in[2];
	dp[2][2] = in[1]+in[2];

	for (int i=3; i<=N; i++) {
		dp[i][0] = max(max(dp[i-1][1], dp[i-1][2]), dp[i-1][0]); // 0잔연속은 이전 단계에서 1번 연속 or 2번 연속 중 큰 값을 고름
		dp[i][1] = dp[i-1][0] + in[i]; // 1잔 연속은 이전 단계에서 마시지 않고 현재 단계에서 마신 값
		dp[i][2] = dp[i-1][1] + in[i]; // 2잔 연속은 이전 단계에서 1잔 연속인 값에 현재 값을 더함
	}

	printf("%d\n", max(max(dp[N][0], dp[N][1]), dp[N][2])); // N단계에서 0, 1, 2 연속 중 큰 값을 고름

	return 0;
}
