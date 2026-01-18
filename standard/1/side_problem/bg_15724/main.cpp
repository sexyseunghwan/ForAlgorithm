#include <iostream>

using namespace std;

int N,M,K;
int ps[1025][1025];

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

    while(K--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int res = ps[x2][y2] - ps[x1-1][y2] - ps[x2][y1-1] + ps[x1-1][y1-1];    
        
        cout << res << '\n';
    }

    return 0;
}