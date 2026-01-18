#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M,R;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M >> R;

    vector<vector<int>> arr(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    int line_cnt = min(M,N) / 2;

    for (int i = 0; i < line_cnt; i++) {
        
        int top = i; 
        int left = i;
        int bottom = N-i-1;
        int right = M-i-1;

        vector<int> vec;
        vec.reserve((2 * (bottom - top)) + (2 * (right - left)));

        // 1. top: left -> right
        for (int j = left; j <= right; j++) {
            vec.push_back(arr[top][j]);
        }

        // 2. right : top -> bottom
        for (int j = top+1; j <= bottom-1; j++) {
            vec.push_back(arr[j][right]);
        }

        // 3. bottom : right -> left
        for (int j = right; j >= left; j--) {
            vec.push_back(arr[bottom][j]);
        }

        // 4. left : bottom -> top
        for (int j = bottom-1; j >= top+1; j--) {
            vec.push_back(arr[j][left]);
        }
        
        int vec_size = vec.size();
        int period = R % vec_size;
        int idx = 0;

        // ============ 재배치 ================
        // 1. top: left -> right
        for (int j = left; j <= right; j++) {
            arr[top][j] = vec[(idx + period) % vec_size];
            idx++;
        }

        // 2. right : top -> bottom
        for (int j = top+1; j <= bottom-1; j++) {
            arr[j][right] = vec[(idx + period) % vec_size];
            idx++;
        }

        // 3. bottom : right -> left
        for (int j = right; j >= left; j--) {
            arr[bottom][j] = vec[(idx + period) % vec_size];
            idx++;
        }

        // 4. left : bottom -> top
        for (int j = bottom-1; j >= top+1; j--) {
            arr[j][left] = vec[(idx + period) % vec_size];
            idx++;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}