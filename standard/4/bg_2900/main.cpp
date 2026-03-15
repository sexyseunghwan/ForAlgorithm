#include <iostream>
#include <vector>

using namespace std;

int N,K,Q;

void something(int jump, int cnt, vector<long long>& vec)
{
    int i = 0;
    while(i < N) {
        vec[i] = vec[i] + cnt;
        i += jump;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> K;

    vector<int> x_cnt(N+1,0);
    vector<long long> vec(N,0);
    
    for (int i = 0; i < K; i++) {
        int x;
        cin >> x;
        x_cnt[x]++;
    }
    
    for (int i = 1; i <= N; i++) {
        if (x_cnt[i] > 0) {
            something(i, x_cnt[i], vec); 
        }
    }
    
    long long acc_sum = 0;
    vector<long long> acc_list(N+1,0);
    
    for (int i = 1; i <= N; i++) {
        acc_sum += vec[i-1];
        acc_list[i] = acc_sum;
    }
    
    cin >> Q;
    
    for (int i = 0; i < Q; i++) {
        int start_idx, end_idx;
        cin >> start_idx >> end_idx;
        
        long long res = acc_list[end_idx+1] - acc_list[start_idx];
        cout << res << '\n';
    }

    return 0;
}