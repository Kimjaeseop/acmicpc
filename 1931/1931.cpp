#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

vector <pair<int, int>> V;
int N;

int cmp(pair<int, int> A, pair<int, int> B)
{
	if (A.second == B.second) {
		return A.first < B.first;
	}

	return A.second < B.second;
}

int main(void)
{
	freopen("input.txt", "r", stdin);

	int ANS = 0;
	int LAST = 0;

	scanf("%d", &N);
	
	V.resize(N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &(V[i].first), &(V[i].second));
	}

	sort(V.begin(), V.end(), cmp);

	for (int i = 0; i < N; i++) {
		if (V[i].first > LAST) {
			ANS++;
			LAST = V[i].second;
		}
	}

	printf("%d\n", ANS);

	return 0;
}


