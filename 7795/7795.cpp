#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	//freopen("input_1.txt", "r", stdin);
	int T, list_a_len, list_b_len;

	scanf("%d", &T);

	for (int test_case = 0; test_case < T; test_case++) {
		scanf("%d %d", &list_a_len, &list_b_len);

		vector<int> list_a(list_a_len);
		vector<int> list_b(list_b_len);

		for (int input_list_a = 0; input_list_a < list_a_len; input_list_a++)
			scanf("%d", &list_a[input_list_a]);

		for (int input_list_b = 0; input_list_b < list_b_len; input_list_b++)
			scanf("%d", &list_b[input_list_b]);

		sort(list_a.begin(), list_a.end());
		sort(list_b.begin(), list_b.end());

		int list_a_index, list_b_index;
		int count, ans;
		list_a_index = list_b_index = count = ans = 0;

		while (list_a_index != list_a_len) {
			if (list_b_index == list_b_len || list_a[list_a_index] <= list_b[list_b_index]) {
				list_a_index++;
				ans += count;
				continue ;
			}

			count++;
			list_b_index++;
		}

		printf("%d\n", ans);
	}

	return 0;
}