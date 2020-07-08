#include <stdio.h>

// 0�� ������ 2 or 5�� ������ �������µ�
// (2 * 5)�� ¦�� ������ ��������.
// ¦�� �̷������ϱ� ������ ���μ����ظ� �ؼ� ���� ���� ���ؼ� ���
// N! �� 2or5�� ���� - (R!�� ���� + (N-R)!�� ����)

// EX ) 5! / 2! = 5*4*3*2*1 / 2*1 = 5*4*3*1 = 60
// 5 : 1��, 2 : 2�� 
// �� : 1��

// combination ����
// N! / (R! * (N-R)!)
// ���丮�� 0�� ���� ���� ���� 1676�� ����

int zero (int N, int div)
{
	int CNT=0;

	for (long long i = div; i <= N; i *= div)
		CNT += N/i;

	return CNT;
}

int main (void)
{
	int N, M;
	long long T, F;

	scanf ("%d %d", &N, &M);

	T = zero (N, 2) - zero(M, 2) - zero(N-M, 2);
	F = zero (N, 5) - zero(M, 5) - zero(N-M, 5);

	printf ("%lld\n", T > F ? F : T);

	return 0;
}

