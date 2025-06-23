#include <iostream>
#include <cstring>

using namespace std;

int N,M;
int map[100][100];
int total_time;
int total_cnt;
bool air_visited[100][100];
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};

void air_dfs(int r, int c) 
{
    air_visited[r][c] = true;
    map[r][c] = 2;

    for (int i = 0; i < 4; i++) {
        int next_r = r + dr[i];
        int next_c = c + dc[i];

        if (next_r >= 0 && next_c >= 0 && next_r < N && next_c < M 
            && !air_visited[next_r][next_c] && map[next_r][next_c] != 1) 
        {
            air_dfs(next_r, next_c);
        }
    }
}

void cheese_search(int r, int c) 
{
    int air_cnt = 0;
    
    for (int i = 0; i < 4; i++) {
        int next_r = r + dr[i];
        int next_c = c + dc[i];

        if (map[next_r][next_c] == 2) ++air_cnt;
        if (air_cnt >= 2) break;
    }

    if (air_cnt >= 2) {
        map[r][c] = 3;
        total_cnt--;
    }
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

            if (input == 1) total_cnt++;
            
            map[i][j] = input;
        }
    }
    
    while(total_cnt > 0) {
        memset(air_visited, 0, sizeof(air_visited));
        total_time++;
        air_dfs(0,0);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] == 1) {
                    cheese_search(i,j);
                }
            }
        }
    }   

    cout << total_time << endl;

    return 0;
}