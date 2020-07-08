#include <stdio.h>

int main(void)
{
    int N;

    scanf("%d", &N);

    for (int i=0; i<N; i++) {
        for (int j=0; j<N+i+1; j++){
			if (N%2==0) {
				if (N-i-1>j)
					printf(" ");
				else if (i%2==0 && j%2==1)
					printf("* ");
				else if (i%2==1 && j%2==0)
					printf("* ");
			}
			else {
				if (N-i-1>j)
					printf(" ");
				else if (i%2==0 && j%2==0)
					printf("* ");
				else if (i%2==1 && j%2==1)
					printf("* ");
			}
		}
		printf("\n");
    }

	return 0;
}
