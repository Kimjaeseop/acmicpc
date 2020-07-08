#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <typeinfo>

using namespace std;

vector <int> V;
vector <int> arr;
vector <int> chk (8001);

int N;
int sum;
int freq;
int MAX=-4001, MIN=4001;
int idx;

int main(void)
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &N);

	arr.resize(N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		
		sum += arr[i];

		if (arr[i] < MIN)
			MIN = arr[i];
		if (arr[i] > MAX)
			MAX = arr[i];

		idx = arr[i] < 0 ? (arr[i] * -1) + 4000 : arr[i];

		chk[idx]+=1;

		if (freq < chk[idx])
			freq = chk[idx];
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < N; i++) {
		if (freq == chk[arr[i] < 0 ? (arr[i]  * -1) + 4000 : arr[i]])
			V.push_back(arr[i]);
	}

	sort(V.begin(), V.end());
	unique(V.begin(), V.end());

	printf("%d\n", (int)round((double)sum/(double)N));
	printf("%d\n", arr[N/2]);
	printf("%d\n", V.size()==1 ? V[0] : V[1]);
	printf("%d\n", MAX-MIN);

	return 0;
}
