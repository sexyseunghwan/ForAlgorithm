#include <iostream>
#include <vector>

using namespace std;
//asdasdasd
//1123123123123asdfasdf
// Bottom-up
// int fibonacci(int n) {
//     vector<int> dp(n+1);

//     dp[0] = 0;
//     dp[1] = 1;

//     for (int i = 2; i <= n; i++) 
//     {
//         dp[i] = dp[i-1] + dp[i-2];
//     }

//     return dp[n];
// }

// int dp_mat[100];
// bool visited[100];

// // Top-down
// int fib(int n) 
// {
//     if (n <= 1) return n;
//     if (visited[n]) return dp_mat[n];
//     visited[n] = true;
//     return dp_mat[n] = dp_mat[n-1] + dp_mat[n-2];
    
// }

vector<int> dp(100, -1);

int fibonacci_top_down(int n)
{
    if (n <= 1) return n;
    if (dp[n] != -1) return dp[n]; /* 메모이제이션 */ 
    return dp[n] = fibonacci_top_down(n-1) + fibonacci_top_down(n-2);
}


int fibonacci_bottom_up(int n)
{
    vector<int> dp(n+1);

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int main()
{
    
    int n;
    cin >> n;

    cout << n << " : " << fibonacci_bottom_up(n) << "" << endl;

    return 0;
}