#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int START,FINISH;
int M;
vector<vector<int>> vec;
vector<bool> visited;
int answer = -1;

void bfs(int current, int depth)
{
    queue<pair<int, int>> que;
    que.push({current, depth});

    while(!que.empty()) {
        pair<int, int> elem = que.front();
        int cur = elem.first;
        int depth = elem.second;
        que.pop();

        visited[cur] = true;

        if (cur == FINISH) {
            answer = depth;
            break;
        }

        for (int next: vec[cur]) {
            if (!visited[next]) {
                que.push({next, depth + 1});
            }
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
        int parent, child;
        cin >> parent >> child;

        vec[parent].push_back(child);
        vec[child].push_back(parent);
    }

    bfs(START, 0);

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