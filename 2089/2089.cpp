#include <stdio.h>

int IN;
int tmp;
int cnt;

int bin (int N) {
	// 2진수로 변환하는데 나머지가 -1로 나와서는 안된다.
	// 0, 1만 나머지로 나와야하는데 -1로 나온 경우는
	// ((N / -2) + 1) + 1의 형태로 변환

	if (N != 0) 
		bin (N%-2==-1 ? (N/-2)+1 : N/-2);
	
	if (cnt)
		printf("%d", N%-2 > 0 ? N%-2 : (N%-2)*-1); // 나머지가 음수일 경우 양수로 치환

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
