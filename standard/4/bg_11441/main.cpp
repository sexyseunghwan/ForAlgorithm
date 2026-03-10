#include <iostream>
#include <vector>

using namespace std;


int N,M;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> N;

    vector<int> sum_result(N+1);
    long long sum_val = 0;

    for (int i = 1; i <= N; i++) {
        int input;
        cin >> input;

        sum_val += input;
        sum_result[i] = sum_val;
    }
    
    cin >> M;

    for (int i = 0; i < M; i++) {
        int start_idx, end_idx;
        cin >> start_idx >> end_idx;
        long res = sum_result[end_idx] - sum_result[start_idx-1];
        cout << res << '\n';
    }

    return 0;
}