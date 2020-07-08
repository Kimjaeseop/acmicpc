#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    int N;
    int in[1001]={0,};
    int dp[1001]={0,};
    int ans=0;

    //freopen("input.txt", "r", stdin);

    cin >> N;

    for (int i=0; i<N; i++)
        cin >> in[i]; // input

    for (int i=0; i<N; i++) {
        int tmp=in[i]; // dp �ʱⰪ ����
		//int tmp=0;
        for (int j=0; j<i; j++) {
            if (in[i]>in[j] && dp[in[j]]+in[i]>tmp) { // ������ ������ �°� ���� ������ ���� ���� ū ���
                tmp = dp[in[j]]+in[i];
            }
        }
        dp[in[i]] = tmp; // index i�� �������� ���� ū ���� ���� ������ ���� ���� ����

        if (dp[in[i]] > ans) // ���� ū ���� ���� ���� ����
            ans = dp[in[i]];
    }   
    
    cout << ans << endl;

    return 0;
}

