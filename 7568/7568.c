#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int w;
	int t;
} node;

int N;
int rank;
node Node[51];

int main(void) 
{
	freopen("input.txt", "r", stdin);

	scanf("%d", &N);

	for (int i=0; i<N; i++) {
		scanf("%d %d", &Node[i].w, &Node[i].t);
	}

	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			if (Node[j].w > Node[i].w && Node[j].t > Node[i].t)
				rank++;
		}
		printf("%d\n", rank+1);
		rank=0;
	}

	return 0;
}
