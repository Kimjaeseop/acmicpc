#include <iostream>
#include <string>
#include <queue>

using namespace std;

queue <int> Q;
string in;
int arr[3] = {1, 2, 4};
int SIZE;
int sum;

int main (void) 
{
	cin >> in;

	for (int i=0; i<in.size(); i++)
		Q.push(in[i]-'0');

	SIZE = Q.size();

	while (SIZE) {
		for (int i=SIZE%3==0 ? 3 : SIZE%3; i>0; i--) {
			if (Q.front())
				sum += arr[i-1];

			Q.pop();
			SIZE--;
		}

		printf("%d", sum);
		sum=0;
	}

	printf("\n");

	return 0;
}
