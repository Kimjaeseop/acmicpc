#include <stdio.h>

int main(void)
{
	int T;
	int H, W, N;

	scanf("%d", &T);
	
	for (int i=0; i<T; i++) {
		scanf("%d %d %d", &H, &W, &N);
		printf("%d%02d\n", N%H==0 ? H : N%H, N%H==0 ? N/H : (N/H)+1);
	}

	return 0;
}
