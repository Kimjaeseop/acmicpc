#include <stdio.h>

int N, arr[12], oper[4];
int minAns, maxAns, saveNum;

void DFS(int depth, int num)
{
	int paramNum = 0;
	//printf("depth : %d, num : %d\n", depth, num);
	if (depth == N) {
		if (num < minAns) {
			minAns = num;
		}

		if (num > maxAns) {
			maxAns = num;
		}

		return ;
	}

	saveNum = num;
	for (int i = 0; i < 4; i++) {
		if (oper[i] > 0) {
			switch(i) {
				case 0:
					//printf("+");
					paramNum = num + arr[depth];
					break;
				case 1:
					//printf("-");
					paramNum = num - arr[depth];
					break;
				case 2:
					//printf("*");
					paramNum = num * arr[depth];
					break;
				case 3:
					//printf("/");
					paramNum = num / arr[depth];
					break;
			}
			oper[i]--;
			DFS(depth+1, paramNum);
			oper[i]++;
		}
	}
}

int main(void)
{
	//freopen("input_3.txt", "r", stdin);

	minAns = 1000000001; maxAns = -1000000001;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < 4;i ++) {
		scanf("%d", &oper[i]);
	}

	DFS(1, arr[0]);

	printf("%d\n%d\n", maxAns, minAns);

	return 0;
}
