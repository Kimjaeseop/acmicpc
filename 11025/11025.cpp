#include <iostream>
#include <vector>

using namespace std;

vector <short> V;
short N, K;
short i;

int main(void)
{
    scanf("%hd %hd", &N, &K);

    for (i = 1; i <= N; i++)
        V.push_back(i);

    i = 0;

    while (V.size() != 1) {
		printf("%d\n", i);
        i += (K - 1);
        i %= V.size();

		printf("%d\n", V[i]);

        V.erase(V.begin() + i);
    }   

	printf("%hd\n", V[0]);

    return 0;
}
