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

	// dp[x][0] : 0�� ���� (���� ��ġ ���� ������ ����)
	// dp[x][1] : 1�� ���� (������ ���� ������ �ʰ� ���� ���� ����)
	// dp[x][2] : 2�� ���� (������ ���� ���̰� ���� �ܵ� ����)
	dp[1][0] = 0;
	dp[1][1] = in[1];

	dp[2][0] = in[1];
	dp[2][1] = in[2];
	dp[2][2] = in[1]+in[2];

	for (int i=3; i<=N; i++) {
		dp[i][0] = max(max(dp[i-1][1], dp[i-1][2]), dp[i-1][0]); // 0�ܿ����� ���� �ܰ迡�� 1�� ���� or 2�� ���� �� ū ���� ����
		dp[i][1] = dp[i-1][0] + in[i]; // 1�� ������ ���� �ܰ迡�� ������ �ʰ� ���� �ܰ迡�� ���� ��
		dp[i][2] = dp[i-1][1] + in[i]; // 2�� ������ ���� �ܰ迡�� 1�� ������ ���� ���� ���� ����
	}

	printf("%d\n", max(max(dp[N][0], dp[N][1]), dp[N][2])); // N�ܰ迡�� 0, 1, 2 ���� �� ū ���� ����

	return 0;
}