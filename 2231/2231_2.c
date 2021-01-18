#include <stdio.h>

int main(void)
{
	int input = 0;
	int num = 0;
	int j = 0;

	scanf("%d", &input);

	for (int i = 1; i < 1000001; i++) {
		j = i;
		num = j;

		while (j) {
			num += j % 10;
			j /= 10;
		}

		if (input == num) {
			printf("%d\n", i);
			return 0;
		}

		num = 0;
	}

	printf("0\n");

	return 0;
}

		
