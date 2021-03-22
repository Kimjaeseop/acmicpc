#include <cstdio>
#include <set>

using namespace std;

int N, M;
int temp;
set<int> s;

int main(void)
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N + M; i++) {
		scanf("%d", &temp);
		s.insert(temp);
	}

	for (int i : s) 
		printf("%d ", i);

	return 0;
}


