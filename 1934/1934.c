#include <stdio.h>

int T;
int A, B;
int gcd, lcm;

int main(void)
{
	scanf("%d", &T);

	for (int i=0; i<T; i++) {
		scanf("%d %d", &A, &B);

		for (int j=(A > B ? A : B); j>0; j--) {
			if (A%j==0 && B%j==0) {
				gcd = j;
				break;
			}
		}

		printf("%d\n", (A*B)/gcd);
	}

	return 0;
}

	
