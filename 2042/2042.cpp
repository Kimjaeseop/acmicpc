#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

long long init(vector<long long> &a, vector<long long> &tree, int node, int start, int end) {
	if (start == end) 
		return tree[node] = a[start]; // tree[node]에 a[start]가 대입된 뒤, tree[node]가 return 된다.
	else
		return tree[node] = init(a, tree, node*2, start, (start+end)/2) + init(a, tree, node*2+1, (start+end)/2+1, end);
}

int main(void)
{
	int n, m, k;

	scanf("%d %d %d", &n, &m, &k);
	vector<long long> a(n);
	
	int h = (int)ceil(log2(n)); // 트리 높이 구하기
	int tree_size = (1 << (h + 1)); // h + 1번 shift하면 2^h를 얻을 수 있다.
	vector<long long> tree(tree_size);

	m += k; // ??

	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}

	printf("h : %d\n", h);
	printf("%d\n", tree_size);

	init(a, tree, 1, 0, n-1);

	while (m--) {
		int t1;

		scanf("%d", &t1);

		if (t1 == 1) {
			int t2;
			long long t3;

			scanf("%d %lld", &t2, &t3);
			t2 -= 1;

			long long diff = t3-a[t2];
			a[t2] = t3;

			update(tree, 1, 0, n-1, t2, diff);
		} else if (t1 == 2) {
			int t2, t3;

			scanf("%d %d", &t2, &t3);
			printf("%lld\n", sum(tree, 1, 0, n-1, t2-1, t3-1));
		}
	}

	for (int i = 0; i < tree_size; i++) {
		printf("%lld\n", tree[i]);
	}

	return 0;
}


