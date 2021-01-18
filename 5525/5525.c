#include <stdio.h>
#include <string.h>

char str[1000001];
char T_STR[2000004] = "I";
int N, M, CNT, T_INT;

int main(void)
{
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		strcat(T_STR, "OI");
	}
	scanf("%s", str);

	T_INT = 1 + 2*N;
	T_STR[T_INT] = '\0';

//	printf("T_STR : %s\n", T_STR);
//	printf("T_INT : %d\n", T_INT);


	char *ptr = str;

	for (int i = 0; i < M - 2; i++) {
		if (*(ptr + i) == 'O')
			continue;

		if (*(ptr + i + 1) == 'I')
			continue;

		if (strncmp(ptr + i, T_STR, T_INT) == 0) {
		//	printf("before %s\n", (ptr + i));
			i += (T_INT-2);
		//	printf("after %s\n", (ptr + i));
			CNT++;
		}
	}

	printf("%d\n", CNT);

	return 0;
}



