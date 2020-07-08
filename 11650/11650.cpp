#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
// ���� �� �Լ� (��������)
bool compare (const pair<int, int> &a, const pair<int, int> &b)
{ 
	if (a.first == b.first)
		return a.second < b.second;

	return a.first < b.first; // ��������
}

int main(void)
{
	vector <pair<int, int> > V;
	int a, b;
	int N;

	scanf("%d", &N);

	for (int i=0; i<N; i++) {
		scanf("%d %d", &a, &b);
		V.push_back(make_pair(a, b));
	}

	sort (V.begin(), V.end(), compare);

	for (int i=0; i<V.size(); i++)
		printf("%d %d\n", V[i].first, V[i].second);

	return 0;
}
