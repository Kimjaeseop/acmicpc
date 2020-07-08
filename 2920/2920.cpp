#include <iostream>
#include <vector>

using namespace std;

vector <int> V(8);
int ans;

// std == 1 // ascending
// std == -1 // descending

int main(void)
{
	for (int i=0; i<8; i++)
		scanf("%d", &V[i]);

	for (int i=1; i<V.size(); i++) {
		if (V[i] < V[i-1]) {
			if (ans==0)
				ans=-1;
			else if (ans==1) {
				printf("mixed\n");
				return 0;
			}
		}
		else if (V[i] > V[i-1]) {
			if (ans==0)
				ans=1;
			else if (ans==-1) {
				printf("mixed\n");
				return 0;
			}
		}
	}

	if (ans==1)
		printf("ascending\n");
	else if (ans==-1)
		printf("descending\n");

	return 0;
}

