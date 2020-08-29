#include <stdio.h>

int n, m;
long long sum = 0;
int height[1000001];
int tmp;
//int* l; int* r;
int l = 1, r = 0, mid = 0;

int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &height[i]);
		if (r < height[i]) r = height[i];
	}

	int other = 0;

	while (l<=r) {
		mid = (l + r) / 2;
		sum = 0;
		for (int i = 0; i < n; i++) {
			if (height[i] - mid > 0) {
				sum += (height[i] - mid);
			}
		}

		if (sum == m) {
			other = mid;
			break;
		}
		else if (sum < m) {
			r = mid-1;
		}
		else if (sum > m) {
			other = mid;
			l = mid+1;
		}
	}

	printf("%d", other);

	return 0;
}
