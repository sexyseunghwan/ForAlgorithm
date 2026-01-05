#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <functional>

using namespace std;


int hourglassSum(vector<vector<int>> arr) {

    int row = arr.size();
    int col = arr[0].size();

    int max_value = -64;
    
    for (int i = 0; i < row - 2; i++) {
        for (int j = 0; j < col - 2; j++) {
            int value = arr[i][j] + arr[i][j+1] + arr[i][j+2]
                                  + arr[i+1][j+1] +   
                        arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
            max_value = max(value, max_value);
        }
    }

    return max_value;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N = 6;

    vector<vector<int>> arr(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    
    int res = hourglassSum(arr);
    
    cout << res << endl;

    return 0;
}