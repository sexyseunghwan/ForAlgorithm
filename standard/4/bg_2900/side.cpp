#include <iostream>
#include <vector>

using namespace std;

int N,K,Q;

void something(int jump, int cnt, vector<long long> &diff_vec) {
    int i = 0;
    while (i < N) {
        diff_vec[i] += cnt;
        diff_vec[i+1] -= cnt;
        i = i + jump;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> K;
    vector<int> cnt(N+1, 0);
    vector<long long> diff_vec(N+1,0);
    vector<int> vec(N,0);  
    vector<long long> acc_vec(N+1,0);
    
    
    for (int i = 0; i < K; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    
    for (int i = 1; i <= N; i++) {
        if (cnt[i] > 0) {
            something(i, cnt[i], diff_vec);
        }
    }

    long long acc_result = 0;

    for (int i = 0; i < N; i++) {
        acc_result += diff_vec[i];
        vec[i] = acc_result;
    }

    long long total = 0;

    for (int i = 1; i <= N; i++) {
        total += vec[i-1];
        acc_vec[i] = total;
    }

    cin >> Q;

    while(Q--) {
        int start_idx, end_idx;
        cin >> start_idx >> end_idx;
        cout << acc_vec[end_idx+1] - acc_vec[start_idx] << '\n';
    }

    return 0;
}