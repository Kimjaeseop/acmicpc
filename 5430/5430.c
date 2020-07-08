#include <stdio.h>
#include <string.h>

int T;
int N;
char S[500001];
char in[500001];
int V[100001];
int num;
int bot, top;
int error;
int SIZE;
int R;

int main(void)
{
	//freopen("input.txt", "r", stdin);

	scanf("%d", &T);

	while (T--) {
		scanf("%s", S);
		scanf("%d", &N);
		bot = error = R = 0;
		top = N;

		scanf("%s", in);
		
		SIZE = strlen(in);
		for (int i = 0, j = 0; i < SIZE; i++) {
			if (in[i] >= '0' && in[i] <= '9') {
				num = num * 10 + (in[i] - '0');
			}
			else if (in[i] == ',' || in[i] == ']') {
				V[j++] = num;
				num = 0;
			}
		}

		SIZE = strlen(S);

		for (int i = 0; i < SIZE; i++) {
			if (S[i] == 'R') {
				R++;
			}
			else if (S[i] == 'D') {
				if (top - bot <= 0) {
					error = 1;
					break;
				}

				if (R % 2 == 0) {
					bot++;
				}
				else {
					top--;
				}
			}
		}
		
		if (error) {
			printf("error\n");
		}
		else {
			printf("[");
			if (R % 2 == 0) {
				for (int i = bot; i < top; i++) {
					printf("%d", V[i]);
					if (i != top - 1) {
						printf(",");
					}
				}
			}
			else {
				for (int i = top - 1; i >= bot; i--) {
					printf("%d", V[i]);
					if (i != bot) {
						printf(",");
					}
				}
			}
			printf("]\n");
		}
	}

	return 0;
}
