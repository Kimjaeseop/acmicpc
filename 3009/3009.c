#include <stdio.h>

int arr[1001][2];
int X, Y;

int main(void)
{
	for (int i = 0; i < 3; i++) {
		scanf("%d %d", &X, &Y);

		arr[X][0]++;
		arr[Y][1]++;
	}

	for (int i = 0; ; i++) {
		if (arr[i][0] == 1) {
			printf("%d ", i);
			break;
		}
	}

	for (int i = 0; ; i++) {
		if (arr[i][1] == 1) {
			printf("%d\n", i);
			break;
		}
	}

	return 0;
}
