#include <iostream>
#include <vector>

using namespace std;

int minimum_swaps(vector<int>& arr) 
{
    vector<bool> visited(arr.size(), false);
    int cnt = 0;

    for (int i = 0; i < arr.size(); i++) {
        int cur_x = arr[i];

        if (cur_x-1 == i || visited[i]) {
            continue;
        }
        
        while(cur_x-1 != i && !visited[i]) {
            int x_pos = cur_x - 1;
            int temp_val = arr[x_pos];
            arr[x_pos] = cur_x;
            cur_x = temp_val;
            cnt++;
        }
    }
    
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    vector<int> vec(N,0);
    
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        vec[i] = x;
    }

    int res = minimum_swaps(vec);

    cout << res << "\n";

    return 0;
}