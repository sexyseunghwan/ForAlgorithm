#include <iostream>
#include <vector>

using namespace std;

int N,M;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    vector<vector<int>> vec(N+1,vector(N+1,0));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int x;
            cin >> x;
            vec[i][j] = vec[i-1][j] + vec[i][j-1] - vec[i-1][j-1] + x;
        }
    }

    for (int i = 0; i < M; i++) {
        int s_r, s_c, e_r, e_c;
        cin >> s_r >> s_c >> e_r >> e_c;
        
        cout << vec[e_r][e_c] - vec[e_r][s_c-1] - vec[s_r-1][e_c] + vec[s_r-1][s_c-1] << "\n";
    }
    
    return 0;
}