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
	if (root == NULL) { // leaf일 경우 메모리 할당 후 값 추가 -> 노드 리턴
		root = (NODE *) malloc (sizeof(NODE));
		root -> L = root -> R = NULL;
		root -> K = key;
		return root;
	}

	if (key <= (root -> K)) {
		root -> L = insert(root -> L, key); // 작은 경우 왼쪽 탐색
	}
	else if (key > (root -> K)) {
		root -> R = insert(root -> R, key); // 큰 경우 오른쪽 탐색
	}

	return root; // 재귀가 끝나고 상위트리로 올라가면서 노드를 반환 // 이 부분 안해주면 틀린다
}

int search(NODE *root, long long key)
{
	if (root == NULL) // 노드가 비어있는 경우 0
		return 0;
	else if ((root -> K) == key) // Search에 성공한 경우 1
		return 1;

	if (key <= (root -> K)) { // 작은경우 왼쪽 탐색
		search(root -> L, key);
	}
	else if (key > (root -> K)) { // 큰 경우 오른쪽 탐색
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
		root = insert(root, in); // 처음 insert 할 때에만 root에 반환받았는데
	} // 잘못 생각한 부분이 결국 재귀가 끝나고 상위트리로 올라오면서 마지막엔 root node를 반환한다.

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		scanf("%lld", &in);
		printf("%d\n", search(root, in));
	}

	return 0;
}
