#include <stdio.h>

int main(void)
{
    int N;

    scanf("%d", &N);

    for (int i=0; i<2*N-1; i++) {
        for (int j=0; j<2*N; j++) {
            if ((j<=i || 2*N-i-1<=j) && i<N)
                printf("*");
            else if ((j<2*N-i-1 || i<j) && N<=i)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}