#include <stdio.h>

int main(void)
{
    int N;

     scanf("%d", &N);

    for (int i=0; i<N; i++) {
        for (int j=0; j<i+N; j++) {
            if (N-i-1<=j && j<=N+i)
                printf("*");
            else
            {
                printf(" ");
            }
            
        }
        printf("\n");
    }     
}