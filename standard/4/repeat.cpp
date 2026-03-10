#include <iostream>
#include <vector>

using namespace std;

int N,M;

long calculate_partial_sum(int n, vector<vector<int>>& queries)
{
    vector<int> def_vec(n+2);

    for (int i = 0; i < queries.size(); i++) {
        int start_idx = queries[i][0];
        int end_idx = queries[i][1];
        int val = queries[i][2];
        
        def_vec[start_idx] += val;
        def_vec[end_idx+1] -= val;
    }
    
    long max_val = 0;
    long arc_dev_val = 0; // A[i]

    for (int i = 1; i <= n; i++) {
        arc_dev_val += def_vec[i];
        max_val = max_val > arc_dev_val ? max_val : arc_dev_val;
    }

    return max_val;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);    

    cin >> N >> M;

    vector<vector<int>> queries(M, vector<int>(3));

    for (int i = 0; i < M; i++) {
        int start_idx, end_idx, val;
        cin >> start_idx >> end_idx >> val;
        
        queries[i][0] = start_idx;
        queries[i][1] = end_idx;
        queries[i][2] = val;
    }

    long result = calculate_partial_sum(N, queries);

    cout << result << endl;

    return 0;
}