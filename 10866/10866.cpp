#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int N;
char input[18];
int top, bot;
int tmp;

int main(void)
{
	int N;

	freopen("input2.txt", "r", stdin);
	scanf("%d", &N);
	vector<int> V(N);

	for (int i=0; i<N; i++) {
		scanf("%s", input);

		if (strcmp(input, "push_back")==0)
			scanf("%d", &V[top++]);
		else if (strcmp(input, "push_front")==0) {
			scanf("%d", &tmp);
			V.insert(V.begin()+bot, tmp);
			top++;
		}
		else if (strcmp(input, "pop_front")==0)
			printf("%d\n", top-bot==0 ? -1 : V[bot++]);
		else if (strcmp(input, "pop_back")==0)
			printf("%d\n", top-bot==0 ? -1 : V[--top]);
		else if (strcmp(input, "size")==0)
			printf("%d\n", top-bot);
		else if (strcmp(input, "empty")==0)
			printf("%d\n", top-bot==0 ? 1 : 0);
		else if (strcmp(input, "front")==0)
			printf("%d\n", top-bot==0 ? -1 : V[bot]);
		else if (strcmp(input, "back")==0)
			printf("%d\n", top-bot==0 ? -1 : V[top-1]);
	}

	return 0;
}
