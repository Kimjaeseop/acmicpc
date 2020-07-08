#include <stdio.h>

int main(void)
{
    int N;

    scanf("%d", &N);

    for (int i=0; i<N*2-1; i++) {
        for (int j=0; j<N; j++) {
            if (N-i-1<=j && i<N)
                printf("*");
            else if (i-N+1<=j && N<=i) {
                printf("*");
            }
            else {
                printf(" ");
            }
            
        }
        printf("\n");
    }

    return 0;
}