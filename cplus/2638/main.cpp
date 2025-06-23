#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int N,M;
int map[100][100];
int total_time;
int total_cnt;
bool air_visited[100][100];
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};

vector<pair<int,int>> cheese_list;

void air_bfs(int r, int c) 
{
    cout << "test" << endl;
    queue<pair<int,int>> que;
    que.push({r,c});

    while(!que.empty()) {
        int cur_r = que.front().first;
        int cur_c = que.front().second;
        que.pop();

        air_visited[cur_r][cur_c] = true;
        map[cur_r][cur_c] = 2;
        
        for (int i = 0; i < 4; i++) {
            int next_r = r + dr[i];
            int next_c = c + dc[i];

            if (next_r >= 0 && next_c >= 0 && next_r < N && next_c < M 
                && !air_visited[next_r][next_c] && map[next_r][next_c] != 1) 
            {
                que.push({next_r, next_c});
            }
        }
    }
}

void cheese_search() 
{
    vector<pair<int,int>> next_cheese;
    
    for (auto [r,c] : cheese_list) {
        
        int air_cnt = 0;

        for (int i = 0; i < 4; i++) {
            int next_r = r + dr[i];
            int next_c = c + dc[i];

            if (map[next_r][next_c] == 2) ++air_cnt;
            if (air_cnt == 2) break;
        }

        if (air_cnt == 2) {
            map[r][c] = 0;
            total_cnt--;
        } else {
            next_cheese.push_back({r,c});
        }
    }

    cheese_list = next_cheese;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int input;
            cin >> input;

            if (input == 1) {
                total_cnt++;
                cheese_list.push_back({i,j});
            }
            
            map[i][j] = input;
        }
    }

    while(total_cnt > 0) {
        memset(air_visited, 0, sizeof(air_visited));
        total_time++;
        air_bfs(0,0);
        cheese_search();
    }

    cout << total_cnt << endl;

    return 0;
}