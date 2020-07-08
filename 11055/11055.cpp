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
        int tmp=in[i]; // dp 초기값 지정
		//int tmp=0;
        for (int j=0; j<i; j++) {
            if (in[i]>in[j] && dp[in[j]]+in[i]>tmp) { // 순열의 순서가 맞고 현재 값과의 합이 가장 큰 경우
                tmp = dp[in[j]]+in[i];
            }
        }
        dp[in[i]] = tmp; // index i를 기준으로 가장 큰 합을 갖는 조합의 합의 수를 저장

        if (dp[in[i]] > ans) // 가장 큰 합을 갖는 수열 저장
            ans = dp[in[i]];
    }   
    
    cout << ans << endl;

    return 0;
}

