#include <stdio.h>

int IN;
int tmp;
int cnt;

int bin (int N) {
	// 2������ ��ȯ�ϴµ� �������� -1�� ���ͼ��� �ȵȴ�.
	// 0, 1�� �������� ���;��ϴµ� -1�� ���� ����
	// ((N / -2) + 1) + 1�� ���·� ��ȯ

	if (N != 0) 
		bin (N%-2==-1 ? (N/-2)+1 : N/-2);
	
	if (cnt)
		printf("%d", N%-2 > 0 ? N%-2 : (N%-2)*-1); // �������� ������ ��� ����� ġȯ

	cnt++;
}

int main (void)
{
	scanf("%d", &IN);

	if (IN)
		bin (IN);
	else
		printf("0\n");

	return 0;
}
