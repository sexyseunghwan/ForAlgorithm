#include <iostream>
#include <vector>

using namespace std;

const int MAX = 9;
vector<int> graph[MAX];
bool visited[MAX];

void dfs(int node) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor: graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main()
{
    // 그래프 연결 정보 (1-based index)
    graph[1] = {2, 3, 8};
    graph[2] = {1, 7};
    graph[3] = {1, 4, 5};
    graph[4] = {3, 5};
    graph[5] = {3, 4};
    graph[6] = {7};
    graph[7] = {2, 6, 8};
    graph[8] = {1, 7};

    // 방문 배열 초기화 -> 어차피 기본값은 false 지만 명시적으로 적어줌
    fill(visited, visited + MAX, false);

    dfs(1);

    return 0;
}