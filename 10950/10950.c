#include <stdio.h>

int main(void)
{
	int r, a, b;

	scanf("%d", &r);

	for (int i = 0; i < r; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
	}

	return 0;
}
