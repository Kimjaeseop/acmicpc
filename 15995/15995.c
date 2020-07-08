#include <stdio.h>

int main(void)
{
	int a, m;

	scanf("%d %d", &a, &m);

	for (int i=1; i<=10000; i++)
		if (((a*i)%m)==1) { 
			printf("%d\n", i);
			return 0;
		}

	printf("0\n");

	return 0;
}
			

