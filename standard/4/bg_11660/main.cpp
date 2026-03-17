#include <iostream>
#include <vector>

using namespace std;

int N,M;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    vector<vector<int>> vec(N, vector<int>(N));
    vector<vector<int>> acc_sum_vec(N+1, vector<int>(N+1));
    
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         int x;
    //         cin >> x;
    //         vec[i][j] = x;
    //     }
    // }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int x;
            cin >> x;
            acc_sum_vec[i][j] = acc_sum_vec[i][j-1] + acc_sum_vec[i-1][j] - acc_sum_vec[i-1][j-1] + x;        
        }
    }

    for (int i = 0; i < M; i++) {
        int s_r, s_c, e_r, e_c;
        cin >> s_r >> s_c >> e_r >> e_c;
        
        int partial_sum = acc_sum_vec[e_r][e_c] - acc_sum_vec[e_r][s_c-1] - acc_sum_vec[s_r-1][e_c] + acc_sum_vec[s_r-1][s_c-1];
        cout << partial_sum << '\n';
    }
    
    return 0;
}