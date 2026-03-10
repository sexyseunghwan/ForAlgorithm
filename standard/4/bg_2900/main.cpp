#include <iostream>
#include <vector>

using namespace std;

int N,K;

void something(int jump, vector<int> &a, vector<long long> &diff_vec) {
    int i = 0;
    while (i < N) {
        a[i] = a[i] + 1;
        diff_vec[i] += 1;
        i = i + jump;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> K;
    vector<int> vec(N,0);
    vector<long long> diff_vec(N,0);

    for (int i = 0; i < K; i++) {
        int input;
        cin >> input;
        something(input, vec, diff_vec);
    }

    return 0;
}