#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
	long long K;
	struct NODE *L;
	struct NODE *R;
} NODE;

long long in;
int N, M;

NODE* insert(NODE *root, long long key)
{
	if (root == NULL) { // leaf�� ��� �޸� �Ҵ� �� �� �߰� -> ��� ����
		root = (NODE *) malloc (sizeof(NODE));
		root -> L = root -> R = NULL;
		root -> K = key;
		return root;
	}

	if (key <= (root -> K)) {
		root -> L = insert(root -> L, key); // ���� ��� ���� Ž��
	}
	else if (key > (root -> K)) {
		root -> R = insert(root -> R, key); // ū ��� ������ Ž��
	}

	return root; // ��Ͱ� ������ ����Ʈ���� �ö󰡸鼭 ��带 ��ȯ // �� �κ� �����ָ� Ʋ����
}

int search(NODE *root, long long key)
{
	if (root == NULL) // ��尡 ����ִ� ��� 0
		return 0;
	else if ((root -> K) == key) // Search�� ������ ��� 1
		return 1;

	if (key <= (root -> K)) { // ������� ���� Ž��
		search(root -> L, key);
	}
	else if (key > (root -> K)) { // ū ��� ������ Ž��
		search(root -> R, key);
	}
}

int main(void)
{
	NODE *root = NULL;
	freopen("input.txt", "r", stdin);

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%lld", &in);
		root = insert(root, in); // ó�� insert �� ������ root�� ��ȯ�޾Ҵµ�
	} // �߸� ������ �κ��� �ᱹ ��Ͱ� ������ ����Ʈ���� �ö���鼭 �������� root node�� ��ȯ�Ѵ�.

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		scanf("%lld", &in);
		printf("%d\n", search(root, in));
	}

	return 0;
}
