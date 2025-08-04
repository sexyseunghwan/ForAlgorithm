#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[6]; // 1번부터 5번 노드 까지
bool visited[6];      // 방문 여부 기록

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

    // 그래프 구성
    graph[1] = {2, 3};
    graph[2] = {};
    graph[3] = {4, 5};
    graph[4] = {};
    graph[5] = {};

    dfs(1);

    return 0;
}