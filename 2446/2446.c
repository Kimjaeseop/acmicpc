#include <stdio.h>

int main(void)
{
    int N;

    scanf("%d", &N);

    for (int i=0; i<2*N-1; i++) {
        for (int j=0; j<2*N-1; j++) {
			if (i<N) {
				if (i<=j && j<2*N-1-i)
					printf("*");
				else if (j<i)
					printf(" ");
			}
			if (i>=N) {
				if (2*N-1-i-1<=j && j<=i)
					printf("*");
				else if (j<2*N-1-i-1)
					printf(" ");
			}
        }
        printf("\n");
    }

    return 0;
}
