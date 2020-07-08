#include <stdio.h>

char arr[2][9] = {{"WBWBWBWB"}, {"BWBWBWBW"}};
char in[51][51];
int MIN=2500;
int tmp1, tmp2, tmp3;
int N, M;

int main(void)
{
	freopen("input2.txt", "r", stdin);

	scanf("%d %d", &N, &M);

	for (int i=0; i<N; i++)
		scanf("%s", in[i]);

	for (int i=0; i<=N-8; i++) {
		for (int j=0; j<=M-8; j++) {
			for (int p=0; p<8; p++) {
				for (int q=0; q<8; q++) {
					if (arr[p%2==0?0:1][q] != in[p+i][q+j])
						tmp1++;
					if (arr[p%2==0?1:0][q] != in[p+i][q+j])
						tmp2++;
				}
			}
			tmp3 = (tmp1 > tmp2 ? tmp2 : tmp1);
			MIN = MIN > tmp3 ? tmp3 : MIN;
			tmp1 = tmp2 = tmp3 = 0;
		}
	}

	printf("%d\n", MIN);

	return 0;
}
