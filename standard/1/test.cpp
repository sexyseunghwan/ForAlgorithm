#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <functional>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N = 5;
    int M = 3;

    int** vec = new int*[N];

    for (int i = 0; i < N; i++)
        vec[i] = new int[M](); // 각 행마다 벡터를 생성 및 0 으로 초기화
    
    // 각 배열의 인덱스에 숫자를 초기화
    for (int i = 0; i < N; i++) {
        vec[i] = new int[M]();
        for(int j = 0; j < M; j++) {
            vec[i][j] = i+j;
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << *(*(vec + i) + j) << " ";
        }
        cout << endl;
    }
    

}