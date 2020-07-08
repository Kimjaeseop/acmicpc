#include <stdio.h>

int main(void)
{
	int X, Y, W, H;

	scanf("%d %d %d %d", &X, &Y, &W, &H);
	int A = W-X;
	int B = H-Y;
/*
	if (A < 0)
		A *= -1;
	if (B < 0)
		B *= -1;

	int ANS = A > B ? B : A;
	ANS = ANS > X ? X : ANS;
	ANS = ANS > Y ? Y : ANS;
*/
	printf("%d\n", A > B ? B : A);

	return 0;
}
