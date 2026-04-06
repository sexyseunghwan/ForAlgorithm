#include <iostream>
#include <vector>

using namespace std;

int minimum_swaps(vector<int>& arr) 
{
    int cnt = 0;

    for (int i = 0; i < arr.size(); i++) {
        while(arr[i]-1 != i) {
            swap(arr[i], arr[arr[i]-1]);
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