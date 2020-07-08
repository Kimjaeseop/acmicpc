#include <stdio.h>

int cnt = 0;
int X;

int main(void)
{
	scanf("%d", &X);

	for (int i = 1; ; i++) {
		for (int j = 1; j <= i; j++) {
			cnt++;

			if (cnt == X) {
				if (i % 2 == 1) {
					printf("%d/%d\n", i - j + 1, j);
				}
				else {
					printf("%d/%d\n", j, i - j + 1);
				}
				return 0;
			}
		}
	}

	return 0;
}
