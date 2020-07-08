#include <stdio.h>
#define MAX 2100000000

int main(void)
{
	long long A, B, C;
	long long ANS=0;

	scanf("%lld %lld %lld", &A, &B, &C);

	if (A > MAX || B > MAX || C > MAX || (B >= C)) {
		printf("-1\n");
		return 0;
	}
	// C���� B�� �� ũ�� ���� �������� �� ����

	// A+(B*ANS) == C*ANS
	// ANS == X
	// A = CX-BX
	// A = (C-B)X, X == A/(C-B)
	long long X = A/(C-B);
	printf("%lld\n", X+1);

	return 0;
}

