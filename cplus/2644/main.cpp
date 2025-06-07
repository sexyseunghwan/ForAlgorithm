#include <iostream>
#include <vector>

using namespace std;

int N;
int START,FINISH;
int M;
vector<vector<int>> vec;
vector<bool> visited;
int answer = -1;


void dfs(int current, int depth) {
    visited[current] = true;
    
    if (current == FINISH) {
        answer = depth;
        return;
    }

    for (int next: vec[current]) {
        if (!visited[next]) {
            dfs(next, depth + 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    cin >> START >> FINISH;
    cin >> M;

    vec.resize(N + 1);
    visited.resize(N + 1);

    for (int i = 0; i < M; i++) {
        int parent;
        int child;
        
        cin >> parent >> child;
        vec[parent].push_back(child);
        vec[child].push_back(parent);
    }
    
    dfs(START, 0);

    cout << answer << endl;

    return 0;
}


// for (int i = 0; i < N+1; i++) {
//     if (!vec[i].empty()) {
//         cout << i << endl;

//         for (int val: vec[i]) {
//             cout << val << " ";
//         }
//         cout << endl;
//     }
// }

// cout << N << endl;
// cout << P1 << endl;
// cout << P2 << endl;
