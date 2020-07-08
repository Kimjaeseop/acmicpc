#include <stdio.h>

int main(void)
{
	int a, b;

	for (; scanf("%d %d", &a, &b)!=EOF;)
		printf("%d\n", a+b);

	return 0;
}


