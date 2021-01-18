#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdio>

using namespace std;

vector<pair<int, int>> V;
int ANS[100001];
int W, N, MAX, RES;

// DP 냅색처럼 풀기 실패

int cmp(pair<int, int> A, pair<int, int> B)
{
    if (A.second == B.second) {
        return A.first < B.first;
    }

    return A.second < B.second;
}

int main(void)
{
	int A, B;

	//freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A >> B;
		V.push_back({A, B});

		if (B > MAX)
			MAX = B;
	}

	sort(V.begin(), V.end(), cmp);

	for (int i = 0; i <= MAX; i++) {
		for (int j = 0; j < i; j++) {
			if (V[j].second > i)
				break;

			for (int p = 0; p < V[j].first; p++) {
				ANS[i] = max(ANS[i], ANS[p] + 1);
			}

			ANS[i] = max(ANS[i], 1);

			if (RES < ANS[i])
				RES = ANS[i];
		}
	}

	cout << RES << endl;

	return 0;
}
