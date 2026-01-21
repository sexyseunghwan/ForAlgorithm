#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M,R;
int arr[100][100];
int oper_arr[1000];

void operation_1() {

    for (int c = 0; c < M; c++) {
        vector<int> vec;
        vec.reserve(N);

        for (int r = 0; r < N; r++) {
            vec.push_back(arr[r][c]);
        }

        reverse(vec.begin(), vec.end());

        for (int r = 0; r < N; r++) {
            arr[r][c] = vec[r];
        }
    }
}

void operation_2() {

    for (int r = 0; r < N; r++) {
        vector<int> vec;
        vec.reserve(M);

        for (int c = 0; c < M; c++) {
            vec.push_back(arr[r][c]);
        }

        reverse(vec.begin(), vec.end());

        for (int c = 0; c < M; c++) {
            arr[r][c] = vec[c];
        }
    }

}

void operation_3() {

    vector<int> vec;
    vec.reserve(N*M);

    for (int c = 0; c < M; c++) {
        for (int r = N-1; r >= 0; r--) {
            vec.push_back(arr[r][c]);
        }
    }

    int temp = N;
    N = M;
    M = temp;
    int idx = 0;

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            arr[r][c] = vec[idx];
            idx++;
        }
    }
}

void operation_4() {

    vector<int> vec;
    vec.reserve(N*M);

    for (int c = M-1; c >= 0; c--) {
        for (int r = 0; r < N; r++) {
            vec.push_back(arr[r][c]);
        }
    }

    int temp = N;
    N = M;
    M = temp;
    int idx = 0;

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            arr[r][c] = vec[idx];
            idx++;
        }
    }
}

void operation_5() {

    vector<vector<int>> vec;
    vec.reserve(4);

    int p_r = N/2;
    int p_c = M/2;

    vector<int> a1;
    a1.reserve(p_r*p_c);

    for (int r = 0; r < p_r; r++) {
        for (int c = 0; c < p_c; c++) {
            a1.push_back(arr[r][c]);
        }
    }

    vec.push_back(a1);

    vector<int> a2;
    a2.reserve(p_r*p_c);

    for (int r = 0; r < p_r; r++) {
        for (int c = p_c; c < M; c++) {
            a2.push_back(arr[r][c]);
        }
    }

    vec.push_back(a2);

    vector<int> a3;
    a3.reserve(p_r*p_c);

    for (int r = p_r; r < N; r++) {
        for (int c = p_c; c < M; c++) {
            a3.push_back(arr[r][c]);     
        }
    }

    vec.push_back(a3);

    vector<int> a4;
    a4.reserve(p_r*p_c);

    for (int r = p_r; r < N; r++) {
        for (int c = 0; c < p_c; c++) {
            a4.push_back(arr[r][c]);
        }
    }

    vec.push_back(a4);

    int idx = 0;

    for (int r = 0; r < p_r; r++) {
        for (int c = 0; c < p_c; c++) {
            arr[r][c] = vec[3][idx];
            idx++;
        }
    }

    idx = 0;

    for (int r = 0; r < p_r; r++) {
        for (int c = p_c; c < M; c++) {
            arr[r][c] = vec[0][idx];
            idx++;
        }
    }

    idx = 0;
    
    for (int r = p_r; r < N; r++) {
        for (int c = p_c; c < M; c++) {
            arr[r][c] = vec[1][idx];
            idx++;    
        }
    }

    idx = 0;

    for (int r = p_r; r < N; r++) {
        for (int c = 0; c < p_c; c++) {
            arr[r][c] = vec[2][idx];
            idx++;
        }
    }
}

void operation_6() {

    vector<vector<int>> vec;
    vec.reserve(4);

    int p_r = N/2;
    int p_c = M/2;

    vector<int> a1;
    a1.reserve(p_r*p_c);

    for (int r = 0; r < p_r; r++) {
        for (int c = 0; c < p_c; c++) {
            a1.push_back(arr[r][c]);
        }
    }

    vec.push_back(a1);

    vector<int> a2;
    a2.reserve(p_r*p_c);

    for (int r = 0; r < p_r; r++) {
        for (int c = p_c; c < M; c++) {
            a2.push_back(arr[r][c]);
        }
    }

    vec.push_back(a2);

    vector<int> a3;
    a3.reserve(p_r*p_c);

    for (int r = p_r; r < N; r++) {
        for (int c = p_c; c < M; c++) {
            a3.push_back(arr[r][c]);     
        }
    }

    vec.push_back(a3);

    vector<int> a4;
    a4.reserve(p_r*p_c);

    for (int r = p_r; r < N; r++) {
        for (int c = 0; c < p_c; c++) {
            a4.push_back(arr[r][c]);
        }
    }

    vec.push_back(a4);

    int idx = 0;

    for (int r = 0; r < p_r; r++) {
        for (int c = 0; c < p_c; c++) {
            arr[r][c] = vec[1][idx];
            idx++;
        }
    }

    idx = 0;

    for (int r = 0; r < p_r; r++) {
        for (int c = p_c; c < M; c++) {
            arr[r][c] = vec[2][idx];
            idx++;
        }
    }

    idx = 0;
    
    for (int r = p_r; r < N; r++) {
        for (int c = p_c; c < M; c++) {
            arr[r][c] = vec[3][idx];
            idx++;    
        }
    }

    idx = 0;

    for (int r = p_r; r < N; r++) {
        for (int c = 0; c < p_c; c++) {
            arr[r][c] = vec[0][idx];
            idx++;
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M >> R;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < R; i++) {
        int input;
        cin >> input;

        if (input == 1) {
            operation_1();
        } else if (input == 2) {
            operation_2();
        } else if (input == 3) {
            operation_3();
        } else if (input == 4) {
            operation_4();
        } else if (input == 5) {
            operation_5();
        } else {
            operation_6();
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }


    return 0;
}