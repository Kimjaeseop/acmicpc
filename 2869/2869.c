#include <stdio.h>
#include <math.h>

int main(void)
{
	int A, B, V;

	scanf("%d %d %d", &A, &B, &V);

	if (A==B && A==V)
		printf("1\n");
	else
		printf("%ld\n", (long)ceil(((double)(V-A)/(double)(A-B)))+1);

	// 3 1 7 // 4 // 7-3 / 2 + 1 = 3
	// 3 1 8 // 4 // 8-3 / 2 + 1 = 3.5


	return 0;
}
