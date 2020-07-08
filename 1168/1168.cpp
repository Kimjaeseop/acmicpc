#include <iostream>
#include <vector>

using namespace std;

vector <int> V;
int N, K;
int i;

int main(void)
{
	scanf("%d %d", &N, &K);

	for (i=1; i<=N; i++)
		V.push_back(i);

	i=0;

	cout << "<";

	while (!V.empty()) {
		i+=(K-1);
		i %= V.size();

		if (V.size()==N)
			printf("%d", V[i]);
		else
			printf(", %d", V[i]);

		V.erase(V.begin()+i);
	}

	cout << ">" << endl;

	return 0;
}
