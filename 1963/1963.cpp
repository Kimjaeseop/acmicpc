#include <iostream>
#include <unistd.h>

int arr[10001];
int T;
int A, B, ANS;

void func(int N, int check[10000], int depth)
{
	int digit[4];

	//printf("N : %d, depth : %d\n", N, depth);

	if (arr[N])
		return ;

	if (N == B) {
		if (ANS > depth)
			ANS = depth;
		return ;
	}
	
	//printf("N : %d, depth : %d\n", N, depth);
	//printf("\n");

	for (int i = 3; i >= 0; i--) {
		digit[i] = N % 10;
		N /= 10;
	}

	digit[0] *= 1000;
	digit[1] *= 100;
	digit[2] *= 10;

	for (int i = 0; i < 10; i++) {
		int d_1 = (i*1000 + digit[1] + digit[2] + digit[3]);
		if (1000 <= d_1 && d_1 < 10000 && !check[d_1]) {
			check[d_1] = 1;
			func(d_1, check, depth + 1);
			check[d_1] = 0;
		}

		int d_2 = (digit[0] + i*100 + digit[2] + digit[3]);
		if (1000 <= d_2 && d_2 < 10000 && !check[d_2]) {
			check[d_2] = 1;
			func(d_2, check, depth + 1);
			check[d_2] = 0;
		}

		int d_3 = (digit[0] + digit[1] + i*10 + digit[3]);
		if (1000 <= d_3 && d_3 < 10000 && !check[d_3]) {
			check[d_3] = 1;
			func(d_3, check, depth + 1);
			check[d_3] = 0;
		}

		int d_4 = (digit[0] + digit[1] + digit[2] + i);
		if (1000 <= d_4 && d_4 < 10000 && !check[d_4]) {
			check[d_4] = 1;
			func(d_4, check, depth + 1);
			check[d_4] = 0;
		}
	}
}

int main(void)
{
	int tmp[10000] = {0,};
	freopen("input.txt", "r", stdin);

	scanf("%d", &T);

	arr[1] = 1;

	for (int i = 2; i < 10000; i++) {
		for (int j = 2; ; j++) {
			if(i * j >= 10000)
				break;

			arr[i * j] = 1;
		}
	}

	for (int i = 0; i < T; i++) {
		ANS = 1e9;
		scanf("%d %d", &A, &B);

		tmp[A] = 1;
		func(A, tmp, 0);
		tmp[A] = 0;

		printf("%d\n", ANS);
		//printf("ANS : %d\n", ANS);
		//printf("===============================\n");
	}

	return 0;
}
