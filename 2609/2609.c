#include <stdio.h>

int A, B;
int lcm, gcd;

int main(void)
{
	//freopen("input.txt", "r", stdin);

	scanf("%d %d", &A, &B);

	for (int i = (A > B ? A : B); i>0; i--)
		if (A%i==0 && B%i==0) {
			gcd = i;
			break;
		}

	// a * b = gcd (a, b) * lcm (a, b) (TRUE)

	printf("%d\n%d\n", gcd, (A*B)/gcd);

	return 0;
}


