#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int in[1001]={0,};
	int dp[1001]={0,};
	int N;
	int val_max, dist_max;

	scanf("%d", &N);

	for (int i=0; i<N; i++)
		scanf("%d", &in[i]);

	dist_max = 1;

	fill(dp, dp+1001, 1); // �⺻ ���̸� 1�� ����

	for (int i=0; i<N; i++) {
		int tmp=0;
		for (int j=0; j<i; j++) { // ���� ��ġ���� ���� ��ġ���� ���� �� �߿� ���� �� ����+1
			if (in[i]>in[j] && dp[in[i]]<dp[in[j]]+1) {
				dp[in[i]] = dp[in[j]]+1;
				if (dp[in[i]] > dist_max) // ���� �� ���̸� ����
					dist_max = dp[in[i]];
			}
		}
	}

	printf("%d\n", dist_max);

	return 0;
}
