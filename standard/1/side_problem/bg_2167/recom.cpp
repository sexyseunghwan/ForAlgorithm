#include <iostream>

using namespace std;

int N,M,K;
int ps[301][301];

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            int input;
            cin >> input;
            ps[i][j] = ps[i-1][j] + ps[i][j-1] + input - ps[i-1][j-1];
        }
    }
    
    cin >> K;

    int a,b,x,y;

    for (int i = 0; i < K; i++) {
        cin >> a >> b >> x >> y;
        
        int res = ps[x][y] - ps[a-1][y] - ps[x][b-1] + ps[a-1][b-1];

        cout << res << endl;
    }

    return 0;
}