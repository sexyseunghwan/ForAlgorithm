#include <iostream>
#include <vector>

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


}

void operation_4() {


}

void operation_5() {


}

void operation_6() {


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