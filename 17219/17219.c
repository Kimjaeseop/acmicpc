#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	char domain[21];
	char pw[21];

	struct node *L;
	struct node *R;
} node;

int N, M;
char in_d[21];
char in_p[21];

// binary search tree
// c의 bst와 c++의 map의 속도가 20배정도 차이난다.

node* insert(node *root, char in_d[21], char in_p[21])
{
	if(root == NULL) {
		root = (node *)malloc(sizeof(node));

		root -> L = root -> R = NULL;
		
		strcpy(root -> domain, in_d);
		strcpy(root -> pw, in_p);

		return root;
	}

	if(strcmp(root -> domain, in_d) <= 0) { // input 값이 더 크거나 같으면 오른쪽
		root -> R = insert(root -> R, in_d, in_p);
	}
	else {
		root -> L = insert(root -> L, in_d, in_p);
	}

	return root;
}

char* search(node *root, char in_d[21])
{
	if(!(strcmp(root -> domain, in_d))) {
		return root -> pw;
	}
	else if(strcmp(root -> domain, in_d) < 0) {
		search(root -> R, in_d);
	}
	else if(strcmp(root -> domain, in_d) > 0) {
		search(root -> L, in_d);
	}
}

int main(void)
{
	node *root = NULL;

	freopen("input.txt", "r", stdin);

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%s %s", in_d, in_p);

		root = insert(root, in_d, in_p);
	}

	for (int i = 0; i < M; i++) {
		scanf("%s", in_d);

		printf("%s\n", search(root, in_d));
	}

	return 0;
}
