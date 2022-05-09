#include <iostream>
#include <vector>

using namespace std;

int T;

double get_div_value(int dividend, int divisor)
{
	return (double)dividend / (double)divisor;
}

int main(void)
{
	freopen("input_1.txt", "r", stdin);

	int N, X, Y;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N >> X >> Y;

		vector<int> V(N);

		double min_value = 10e7;
		int min_index = 0;

		for (int j = 0; j < N; j++) {
			cin >> V[j];

			if (get_div_value(X, V[j]) < min_value) {
				min_value = get_div_value(X, V[j]);
				min_index = j;
			}
		}

		if (min_index == N-1) {
			cout << 0 << endl;
			continue;
		}

		if (get_div_value(X-Y, V[N-1]) + 1 >= min_value) {
			cout << -1 << endl;
			continue;
		}

		int start = 0, end = Y, mid, answer;
		double second = 0;

		while (start <= end) {
			mid = (start + end) / 2;

			second = get_div_value(X-mid, V[N-1]) + 1;

			if (second > min_value)
				start = mid + 1;
			else if (second <= min_value) {
				end = mid - 1;

				if (second < min_value)
					answer = mid;
			}
		}
		printf("%d\n", answer);
	}

	return 0;
}