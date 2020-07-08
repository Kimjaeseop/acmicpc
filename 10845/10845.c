#include <stdio.h>
#include <string.h>

int N;
int queue[10001];
int top, bot;
char input[12];

int main(void)
{
	freopen("input.txt", "r", stdin);

	scanf("%d", &N);
	
	for (int i=0; i<N; i++) {
		scanf("%s", input);

		if (strcmp(input, "push")==0)
			scanf("%d", &queue[top++]);
		else if (strcmp(input, "front")==0)
			printf("%d\n", top-bot==0 ? -1 : queue[bot]);
		else if (strcmp(input, "back")==0)
			printf("%d\n", top-bot==0 ? -1 : queue[top-1]);
		else if (strcmp(input, "size")==0)
			printf("%d\n", top-bot);
		else if (strcmp(input, "empty")==0)
			printf("%d\n", top-bot==0 ? 1 : 0);
		else if (strcmp(input, "pop")==0) {
			if (top-bot==0)
				printf("-1\n");
			else
				printf("%d\n", queue[bot++]);
		}
	}

	return 0;
}
