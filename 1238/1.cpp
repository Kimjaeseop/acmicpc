#include <cstdio>
#include <vector>

using namespace std;

int main(void)
{
	vector<int> V;
	for (int i = 0; i < 10; i++) {
		V.push_back(i);
	}

	int a;

	for (auto iter : V) {
		a = iter;
		a += 10;
	}

	for (auto iter : V) {
		printf("%d\n", iter);
	}

	return 0;
}
