#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_N = 100; // 최대 아이템 개수
const int MAX_W = 1000; // 최대 무게

int dp[MAX_N + 1][MAX_W + 1];

int main()
{
    int N = 4; // 가방 빈칸
    int W = 7; // 최대 하중
    
    int weights[] = {6,4,3,2};
    int values[] = {13,8,6,4};

    memset(dp, 0, sizeof(dp));
    
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (weights[i-1] <= j) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - weights[i-1]] + values[i-1]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }


    cout << dp[N][W] << endl;

    return 0;
}


