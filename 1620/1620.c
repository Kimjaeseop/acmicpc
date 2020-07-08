#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int idx;
	char name[21];

	struct node *l;
	struct node *r;
} node;

int N, M;

char arr[100001][21];
char in[21];

// binart search tree
// 크거나 같은 경우 오른쪽
// 작으면 왼쪽

node* insert(node *root, char *k, int idx)
{
	if(root == NULL) {
		root = (node *)malloc(sizeof(node));
		root -> l = root -> r = NULL;
		root -> idx = idx;
		strcpy(root -> name, k);

		return root;
	}

	if (strcmp(root -> name, k) > 0) {
		root -> l = insert(root -> l, k, idx);
	}
	else if(strcmp(root -> name, k) <= 0) {
		root -> r = insert(root -> r, k, idx);
	}

	return root;
}

int search_key(node *root, char *k)
{
	if(!(strcmp(root -> name, k))) {
		return root -> idx;
	}
	else if(strcmp(root -> name, k) > 0) {
		search_key(root -> l, k);
	}
	else if(strcmp(root -> name, k) < 0) {
		search_key(root -> r, k);
	}
}

int main(void)
{
	node *root = NULL; // 실수를 반복,,,,, 초기화를 잘하자

	freopen("input.txt", "r", stdin);

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		scanf("%s", arr[i]);

		root = insert(root, arr[i], i);
	}

	for (int i = 0; i < M; i++) {
		scanf("%s", in);

		if (in[0] >= '0' && in[0] <= '9') {
			printf("%s\n", arr[atoi(in)]);
		}
		else {
			printf("%d\n", search_key(root, in));
		}
	}

	return 0;
}
