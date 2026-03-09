#include <iostream>
#include <vector>

using namespace std;

int N,M;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> N >> M;
    
    vector<long> acc_vec(N+1,0);

    for (int i = 1; i <= N; i++) {
        int input;
        cin >> input;

        acc_vec[i] = input + acc_vec[i-1];
    }

    for (int i = 0; i < M; i++) {
        int start_idx, end_idx;
        cin >> start_idx >> end_idx;

        long res = acc_vec[end_idx] - acc_vec[start_idx-1];
        cout << res << '\n';
    }

    return 0;
}