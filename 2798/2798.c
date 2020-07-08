#include <stdio.h>

int N, M;
int input[101];
int ans;

int main(void)
{
	scanf("%d %d", &N, &M);

	for (int i=0; i<N; i++)
		scanf("%d", &input[i]);

	for (int i=0; i<N-2; i++) {
		for (int j=i+1; j<N-1; j++) {
			for (int p=j+1; p<N; p++) {
				int tmp = input[i]+input[j]+input[p];

				if (tmp<=M && tmp>ans)
					ans=tmp;
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}

