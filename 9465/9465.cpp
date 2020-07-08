#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

// ���ͺ��� bfs ���� ����.

// max(dp[i-1] + N, dp[i-2] + N)
// ���� Ŀ�� ����

int main(void)
{
	int in[2][100001]={0,};
	int dp[2][100001]={0,};
	int T;
	int N;
	int tmp=0;

	scanf("%d", &T);

	for (int t=0; t<T; t++) {
		scanf("%d", &N);

		for (int i=0; i<=1; i++) // input
			for (int j=1; j<=N; j++)
				scanf("%d", &in[i][j]);

		dp[0][1]=in[0][1]; // �� ó�� �� ����
		dp[1][1]=in[1][1];

		// ���� ���� �ݴ� ������ ���� �� ū ��츦 ���
		for (int i=2; i<=N; i++) { // MAX(������, �� �ܰ� ���� �ݴ� ��ġ ��) + ���� ��
			dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + in[0][i];
			dp[1][i] = max(dp[0][i-1], dp[0][i-2]) + in[1][i];
		}

		printf("%d\n", max(dp[0][N],dp[1][N]));
	}

	return 0;
}

