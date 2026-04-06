#include <iostream>
#include <vector>

using namespace std;


int minimum_swaps(vector<int>& arr) 
{
    int size_arr = arr.size();
    vector<bool> visited(size_arr, false);
    
    int total_cycle = 0;

    for (int i = 0; i < size_arr; i++) {
        
        if (arr[i] - 1 == i || visited[i] == true) {
            continue;
        }
        
        int cur = i;
        int partial_cycle = 0;

        while(!visited[cur]) {
            partial_cycle++;
            visited[cur] = true;
            cur = arr[cur] - 1;
        }

        if (partial_cycle > 0) {
            total_cycle += (partial_cycle - 1);
        }
    }

    return total_cycle;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    vector<int> arr(N,0);
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    int result = minimum_swaps(arr);

    cout << result << "\n";

    return 0;
}