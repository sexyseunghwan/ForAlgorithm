#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int N;
int map[100][100];
int visited[100][100];
int cur_area;
int max_area = 1;
int min_height = 101;
int max_height;
int dr[4] = {0,0,-1,1};
int dc[4] = {1,-1,0,0};

void bfs(int r, int c, int height) {

    queue<pair<int, int>> que;
    que.push({r,c});
    
    while (!que.empty()) {  
        pair<int, int> p = que.front();
        int cur_r = p.first;
        int cur_c = p.second;
        
        visited[cur_r][cur_c] = 1;

        que.pop();
        
        for (int i = 0; i < 4; i++) {
            int new_r = cur_r + dr[i];
            int new_c = cur_c + dc[i];

            if (new_r >= 0 && new_c >= 0 && new_r < N && new_c < N && visited[new_r][new_c] == 0 && map[new_r][new_c] > height) {
                que.push({new_r, new_c});
            }
        }
    }
}


int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int input;
            cin >> input;

            map[i][j] = input;

            min_height = min(min_height, input);
            max_height = max(max_height, input);
        }
    }

    for (int i = min_height; i < max_height; i++) {
        
        memset(visited, 0, sizeof(visited));
        cur_area = 0;
        
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (map[j][k] > i && visited[j][k] == 0) {
                    cur_area++;
                    bfs(j, k, i);
                }
            }
        }

        max_area = max(max_area, cur_area);

    }

    cout << max_area << endl;

    return 0;
}