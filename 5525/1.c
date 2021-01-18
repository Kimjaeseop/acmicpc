#include <stdio.h>

int main(void)
{
	int T_1, T_2;

	T_1 |= 1 << 1;
	T_1 |= 1 << 3;
	T_1 |= 1 << 5;

	T_2 |= 1 << 1;
	T_2 |= 1 << 3;

	printf("%d\n", (T_1 & T_2));
	printf("%d\n", (T_1 >> 1) & T_2);
	printf("%d\n", (T_1 >> 2) & T_2);

	return 0;
}
