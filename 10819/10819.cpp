#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int main(void)
{
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	vector<int> V;
	vector<int> MAX_VEC;

	int N, MAX, tmp;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		V.push_back(tmp);
	}

	sort(V.begin(), V.end());
	MAX = 0;

	do {
		int sum = 0;

		for (auto iter = V.begin(); iter != (V.end()-1); iter++)
			sum += abs(*iter - *(iter + 1));

		if (sum > MAX) 
			MAX = sum;

	} while (next_permutation(V.begin(), V.end()));

	cout << MAX << endl;

	return 0;
}





