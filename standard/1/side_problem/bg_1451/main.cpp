#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N,M;
long long ps[51][51];

long long p_sum(int r1, int c1, int r2, int c2) {
    return ps[r2][c2] - ps[r1-1][c2] - ps[r2][c1-1] + ps[r1-1][c1-1];
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    string s;

    for (int i = 1; i <= N; i++) {
        cin >> s;
        for (int j = 1; j <= M; j++) {
            int input = s[j-1] - '0';
            ps[i][j] = ps[i-1][j] + ps[i][j-1] + input - ps[i-1][j-1];
        }
    }
    
    long long max_value = LLONG_MIN;
    
    // 1. 모두 세로로만 구분되어 있는 경우
    for (int c1 = 1; c1 <= M-2; c1++) {
        for (int c2 = 1; c2 <= M-1; c2++) {
            long long partial_sum1 = p_sum(1,1,N,c1);
            long long partial_sum2 = p_sum(1,c1+1,N,c2);
            long long partial_sum3 = p_sum(1,c2+1,N,M);

            long long total_sum = partial_sum1*partial_sum2*partial_sum3;

            max_value = max(total_sum, max_value);
        }
    }
    
    // 2. 모두 가로로만 구분되어 있는 경우
    for (int r1 = 1; r1 <= N-2; r1++) {
        for (int r2 = 1; r2 <= N-1; r2++) {
            long long partial_sum1 = p_sum(1,1,r1,M);
            long long partial_sum2 = p_sum(r1+1,1,r2,M);
            long long partial_sum3 = p_sum(r2+1,1,N,M);

            long long total_sum = partial_sum1*partial_sum2*partial_sum3;

            max_value = max(total_sum, max_value);
        }
    }


    // 3. 왼쪽이 큰 경우
    for (int c = 1; c <= M-1; c++) {
        for (int r = 1; r <= N-1; r++) {
            long long partial_sum1 = p_sum(1,1,N,c);
            long long partial_sum2 = p_sum(1,c+1,r,M);
            long long partial_sum3 = p_sum(r+1,c+1,N,M);

            long long total_sum = partial_sum1*partial_sum2*partial_sum3;

            max_value = max(total_sum, max_value);
        }
    }

    // 4. 오른쪽이 큰 경우
    for (int r = 1; r <= N-1; r++) {
        for (int c = 1; c <= M-1; c++) {
            long long partial_sum1 = p_sum(1,1,r,c);
            long long partial_sum2 = p_sum(r+1,1,N,c);
            long long partial_sum3 = p_sum(1,c+1,N,M);

            long long total_sum = partial_sum1*partial_sum2*partial_sum3;

            max_value = max(total_sum, max_value);
        }
    }

    // 5. 위쪽이 큰 경우
    for (int r = 1; r <= N-1; r++) {
        for (int c = 1; c <= M-1; c++) {
            long long partial_sum1 = p_sum(1,1,r,M);
            long long partial_sum2 = p_sum(r+1,1,N,c);
            long long partial_sum3 = p_sum(r+1,c+1,N,M);

            long long total_sum = partial_sum1*partial_sum2*partial_sum3;

            max_value = max(total_sum, max_value);
        }
    }


    // 6. 아래쪽이 큰 경우
    for (int c = 1; c <= M-1; c++) {
        for (int r = 1; r <= N-1; r++) {
            long long partial_sum1 = p_sum(1,1,r,c);
            long long partial_sum2 = p_sum(1,c+1,r,M);
            long long partial_sum3 = p_sum(r+1,1,N,M);

            long long total_sum = partial_sum1*partial_sum2*partial_sum3;

            max_value = max(total_sum, max_value);
        }
    }
    
    cout << max_value << endl;

    return 0;
}