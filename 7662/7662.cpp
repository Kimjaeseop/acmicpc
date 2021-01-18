#include <iostream>
#include <queue>

using namespace std;

// fail

int T, N, num;
char c;
int m_c, l_c, i_c;

int main(void)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("input.txt", "r", stdin);

    cin >> T;

    while (T--) {
        cin >> N;
        i_c = l_c = m_c = 0;
        priority_queue<int, vector<int>, greater<int>> min_q;
        priority_queue<int, vector<int>, less<int>> max_q;

        for (int i = 0; i < N; i++) {
            cin >> c >> num;
            //cout << c << " " << num << endl;

            if (c == 'I') {
                i_c++;
                min_q.push(num); max_q.push(num);
            }
            else if (c == 'D' && i_c - m_c - l_c > 0){
                if (num == 1) {
                    m_c++;

                    //cout << "max : " << max_q.top() << "\n";
                    max_q.pop();
                }
                else {
                    l_c++;

                    //cout << "min : " << min_q.top() << "\n";
                    min_q.pop();
                }

                if (i_c - m_c - l_c == 0) {
                    max_q = priority_queue <int, vector<int>, less<int>>();
                    min_q = priority_queue <int, vector<int>, greater<int>>();

                    i_c = l_c = m_c = 0;
                }
            }
        }

        if (i_c - m_c - l_c) {
            if (N - l_c > 0) cout << max_q.top();
            if (N - m_c > 0) cout << " " << min_q.top();
            cout << "\n";
        }
        else
            cout << "EMPTY" << "\n";

    }

    return 0;
}
