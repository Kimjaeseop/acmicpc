#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

vector<pair<int, int>> V;
vector<int> chk; 

int N;
int SUM, MAX;
int LAST = 0;
bool found;

int main(void)
{
	//freopen("input.txt", "r", stdin);

	scanf("%d", &N);

	V.resize(N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &(V[i].first), &(V[i].second));
	}

	sort(V.begin(), V.end());

	/*
	for (auto iter : V) {
		cout << iter.first <<  " " << iter.second << endl;
	}
	*/

	for (int i = 0; i < N; i++, SUM = 0) {
		found = false;

		for (auto iter : chk) {
			if (iter == i) {
				found = true;
				break;
			}
		}

		if (found)
			continue;

		for (int j = i; j < N; j++) {
			if (V[j].first > LAST) {
				SUM++;
				LAST = V[i].second;
				chk.push_back(
			}
		}
		if (SUM > MAX)
			MAX = SUM;
	}

	cout << MAX << endl;

	return 0;
}


