#include <cstdio>
#include <unistd.h>

using namespace std;

#define MAX(a, b) a > b ? a : b

int N, M, maxOfArray;
int arr[100001];

int main(void)
{
	int low, high, mid, cnt, ans;
	int sumOfArray;

	low = high = mid = sumOfArray = ans = cnt = 0;

	//freopen("input_1.txt", "r", stdin);

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		maxOfArray = MAX(arr[i], maxOfArray);
	}

	low = maxOfArray;
	high = maxOfArray * (N / M + 1);

	while (low <= high) {
		mid = (high + low) / 2;

		sumOfArray = 0;
		cnt = 1;

		for (int i = 0; i < N; i++) {
			sumOfArray += arr[i];

			if (mid < sumOfArray) {
				i--;
				sumOfArray = 0;
				cnt++;
			}
		}

        /*
		if (sumOfArray != 0) {
			cnt++;
		}
        */

		if (cnt > M) {
			low = mid+1;
		}
		else if (cnt <= M) {
			ans = mid;
			high = mid-1;
		}
	}

	printf("%d\n", ans);

	return 0;
}

