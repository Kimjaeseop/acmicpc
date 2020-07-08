#include <stdio.h>
#include <string.h>

char operand[5];
int stack[100002];
int top;
int num;

int main (void)
{
	int N;

	scanf("%d", &N);

	for (int i=0; i<N; i++) {
		scanf("%s", operand);

		if (strcmp(operand, "push")==0) {
			scanf("%d", &num); 
			stack[top++] = num;
		}
		else if (strcmp(operand, "top")==0) {
			if (top==0)
				printf("-1\n");
			else
				printf("%d\n", stack[top-1]);
		}
		else if (strcmp(operand, "pop")==0) {
			if (top==0)
				printf("-1\n");
			else {
				printf("%d\n", stack[top-1]);
				top--;
			}
		}
		else if (strcmp(operand, "size")==0)
			printf("%d\n", top);
		else if (strcmp(operand, "empty")==0)
			printf("%d\n", top==0 ? 1 : 0);

		memset(operand, 5, 0);
	}

	return 0;
}
