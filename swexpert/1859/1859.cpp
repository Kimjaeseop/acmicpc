#include <iostream>
#include <stack>

using namespace std;

stack <int> L;
stack <int> R;
int T;
int N;
int sum;

int main (void)
{
	scanf ("%d", &T);

	for (int i=0; i<T; i++) {
		scanf("%d", &N);
	}

	printf ("%d\n", R.top());


	return 0;
}
