#include <stdio.h>

int main(void)
{
	int a, b, n, w;
	int cnt=0;
	int ANS1, ANS2;

	scanf("%d %d %d %d", &a, &b, &n, &w);

	for (int i=1; i<=1000; i++) {
		for (int j=1; j<=1000; j++) {
			if ((i*a)+(j*b) == w && i+j==n) {
				cnt++;
				ANS1=i; ANS2=j;
			}
		}
	}

	if ((ANS1==0 || ANS2==0) || cnt != 1)
		printf("-1\n");
	else
		printf("%d %d\n", ANS1, ANS2);

	return 0;
}
