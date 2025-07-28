#include <iostream>
#include <vector>

using namespace std;

// Bottom-up
int fibonacci(int n) {
    vector<int> dp(n+1);

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) 
    {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int dp_mat[100];
bool visited[100];

// Top-down
int fib(int n) 
{
    if (n <= 1) return n;
    if (visited[n]) return dp_mat[n];
    visited[n] = true;
    return dp_mat[n] = dp_mat[n-1] + dp_mat[n-2];
    
}


int main()
{
    
    int n;
    cin >> n;

    cout << n << " : " << fibonacci(n) << "" << endl;


    return 0;
}