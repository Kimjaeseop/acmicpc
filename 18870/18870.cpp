#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

vector<int> V1;
vector<int> V2;

int N;

// from geeksforgeeks
int getIndex(int K);

int main(void)
{
	int in;

	//freopen("input_1.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> in;

		V1.push_back(in);
		V2.push_back(in);
	}

	// unique 실행 조건 -> 오름차순 정렬
	sort(V2.begin(), V2.end());
	unique(V2.begin(), V2.end());

	for (int i = 0; i < N; i++) {
		cout << getIndex(V1[i]) << endl;
	}

	return 0;
}

int getIndex(int K) {
	auto it = find(V2.begin(), V2.end(), K);

	if (it != V2.end())
		return it - V2.begin();
	else
		return -1;
}

