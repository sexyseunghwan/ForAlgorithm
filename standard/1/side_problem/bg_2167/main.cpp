#include <iostream>

using namespace std;

int N,M,K;
int arr[300][300];


int partial_sum(int a, int b, int x, int y) 
{
    int total_sum = 0;
    
    for (int i = a-1; i < x; i++) {
        for (int j = b-1; j < y; j++) {
            total_sum += arr[i][j];
        }
    }

    return total_sum;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
    
    cin >> K;

    int a,b,x,y;

    for (int i = 0; i < K; i++) {
        cin >> a >> b >> x >> y;
        int res = partial_sum(a,b,x,y);

        cout << res << endl;
    }

    return 0;
}