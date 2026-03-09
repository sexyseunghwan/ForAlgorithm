#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N,M;


long calculate_partial_sum(int n, vector<vector<int>>& queries)
{
    vector<long> result_vec(n+2,0);

    for (int i = 0; i < queries.size(); i++) {
        int start_idx = queries[i][0];
        int end_idx = queries[i][1];
        long value = queries[i][2];

        result_vec[start_idx] += value;
        result_vec[end_idx+1] -= value;
    }
    
    long max_value = 0;
    long sum_val = 0;

    for (int i = 1; i <= n; i++) {
        sum_val += result_vec[i];
        max_value = max_value > sum_val ? max_value : sum_val;
    }
    
    return max_value;
}

// 아래 처럼 하면 시간복잡도에서 걸림.***
// long calculate_partial_sum(int n, vector<vector<int>>& queries) 
// {
    
//     long max_value = INT64_MIN;
//     vector<long> result_vec(n,0);    

//     for (int i = 0; i < queries.size(); i++) {
//         int start_idx = queries[i][0]-1;
//         int end_idx = queries[i][1]-1;
//         int value = queries[i][2];
        
//         for (int j = start_idx; j <= end_idx; j++) {
//             long sum_val = result_vec[j] + value;
//             max_value = max_value > sum_val ? max_value : sum_val;   
//             result_vec[j] = sum_val;
//         }
//     }
    
//     return max_value;
// }


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    // N: 계산할 배열 사이즈, M: 계산 쿼리 사이즈
    cin >> N >> M;
    
    vector<vector<int>> cal_vec(M, vector<int>(3));
    
    for (int i = 0; i < M; i++) {
        int a,b,k;
        cin >> a >> b >> k;
        
        cal_vec[i][0] = a;
        cal_vec[i][1] = b;
        cal_vec[i][2] = k;
    }
    
    long result = calculate_partial_sum(N, cal_vec);
    
    cout << result << endl;
    
    return 0;
}