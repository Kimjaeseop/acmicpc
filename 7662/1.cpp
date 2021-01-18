#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	vector<int> V;


	V.push_back(1);
	V.push_back(10);
	V.push_back(5);
	V.push_back(99);
	V.push_back(100);

	sort(V.begin(), V.end(), greater<int>());

	for (auto iter : V) {
		cout << iter << endl;
	}

	return 0;
}
