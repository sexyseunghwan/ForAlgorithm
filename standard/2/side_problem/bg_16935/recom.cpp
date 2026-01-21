#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M,R;
int oper_arr[1000];


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M >> R;

    vector<vector<int>> a(N, vector<int>(M));

    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++)
            cin >> a[r][c];

    // 1. 상하 반전
    auto op1 = [&]() {
        for (int r = 0; r < N/2; r++) {
            for (int c = 0; c < M; c++) {
                swap(a[r][c], a[N-1-r][c]);
            }
        }
    };

    // 2. 좌우 반전
    auto op2 = [&]() {
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M/2; c++) {
                swap(a[r][c], a[r][M-1-c]);
            }
        }
    };

    // 3) 오른쪽 90도 회전
    auto op3 = [&]() {
        vector<vector<int>> b(M,vector<int>(N));

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                b[c][N-1-r] = a[r][c];
            }
        }

        a.swap(b);
        swap(N,M);
    };

    // 4) 왼쪽으로 90도 회전
    auto op4 = [&]() {
        vector<vector<int>> b(M,vector<int>(N));

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                b[M-1-c][r] = a[r][c];
            }
        }

        a.swap(b);
        swap(N,M);
    };


    // 5)
    auto op5 = [&]() {
        
        int p_r = N/2;
        int p_c = M/2;

        vector<vector<int>> b(N,vector<int>(M));
        
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                int nr = r;
                int nc = c;
                
                if (nr < p_r && nc < p_c) {
                    // 좌상
                    nc = c + p_c;
                } else if (nr < p_r && nc >= p_c) {
                    // 우상
                    nr = r + p_r;
                } else if (nr >= p_r && nc >= p_c) {
                    // 우하
                    nc = c - p_c;
                } else if (nr >= p_r && nc < p_c) {
                    // 좌하
                    nr = r - p_r;
                }

                b[nr][nc] = a[r][c];
            }
        }
        
        a.swap(b);

    };

    auto op6 = [&]() {
        
        int p_r = N/2;
        int p_c = M/2;

        vector<vector<int>> b(N,vector<int>(M));

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                int nr = r;
                int nc = c;

                if (r < p_r && c < p_c) {
                    // 좌상
                    nr = r + p_r;
                } else if (r < p_r && c >= p_c) {
                    // 우상 
                    nc = c - p_c;
                } else if (r >= p_r && c >= p_c) {
                    // 우하
                    nr = r - p_r;
                } else if (r >= p_r && c < p_c) {
                    // 좌하
                    nc = c + p_c;
                }

                b[nr][nc] = a[r][c];
            }
        }

        a.swap(b);
    };

    for (int i = 0; i < R; i++) {
        int x;
        cin >> x;
        if (x == 1) op1();
        else if (x == 2) op2();
        else if (x == 3) op3();
        else if (x == 4) op4();
        else if (x == 5) op5();
        else op6();
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }


    return 0;
}