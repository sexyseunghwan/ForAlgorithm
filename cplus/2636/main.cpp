#include <iostream>

using namespace std;

int N,M;
int map[100][100];
int air_map[100][100];
int cheese_cnt;
int res_time;
int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};
int prev_cnt;
int cur_total_cnt;

void clear()
{
    for (int i = 0; i < N; i++)
    {
        fill(air_map[i], air_map[i] + M, 0);
    }
}

// void dfs(int cur_r, int cur_c)
// {
//     visited[cur_r][cur_c] = 1;

//     int del_target = 0;

//     for (int i = 0; i < 4; i++)
//     {
//         int next_r = cur_r + dr[i];
//         int next_c = cur_c + dc[i];

//         if (next_r >= 0 && next_c >= 0 && next_r < N && next_c < M && map[next_r][next_c] == 0 && visited[next_r][next_c] == 0)
//         {
//             ++del_target;
//             break;
//         }
//     }

//     if (del_target > 0)
//     {
//         --cur_total_cnt;
//         map[cur_r][cur_c] = 0;
//     }

//     for (int i = 0; i < 4; i++)
//     {
//         int next_r = cur_r + dr[i];
//         int next_c = cur_c + dc[i];

//         if (next_r >= 0 && next_c >= 0 && next_r < N && next_c < M && map[next_r][next_c] == 1 && visited[next_r][next_c] == 0)
//         {
//             dfs(next_r, next_c);
//         }
//     }

// }

void dfs(int cur_r, int cur_c)
{
    air_map[cur_r][cur_c] = 1;
    
    for (int i = 0; i < 4; i++)
    {
        int next_r = cur_r + dr[i];
        int next_c = cur_c + dc[i];

        if (next_r >= 0 && next_c >= 0 && next_r < N && next_c < M && map[next_r][next_c] == 0 && air_map[next_r][next_c] == 0)
        {
            dfs(next_r, next_c);
        }
    }
}

void check_cheese(int cur_r, int cur_c)
{
    bool air_touch = false;
    
    for (int i = 0; i < 4; i++)
    {
        int next_r = cur_r + dr[i];
        int next_c = cur_c + dc[i];

        if (next_r >= 0 && next_c >= 0 && next_r < N && next_c < M && map[next_r][next_c] == 0 && air_map[next_r][next_c] == 1)
        {
            air_touch = true;
            break;
        }
    }

    if (air_touch) {
        map[cur_r][cur_c] = 0;
        --cur_total_cnt;
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> N >> M;

    int air_r, air_c;
    bool air_flag = false;

    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            int input;
            cin >> input;
            if (input == 1) ++prev_cnt;
            if (!air_flag && input == 0) {
                air_r = i;
                air_c = j;
            }
            map[i][j] = input;
        }
    }
    
    cur_total_cnt = prev_cnt;

    while(true)
    {
        prev_cnt = cur_total_cnt;

        dfs(air_r, air_c);

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (map[i][j] == 1)
                {
                    check_cheese(i,j);
                }
            }
        }
        
        clear();
        
        // cout << "==============================" << endl;

        // for (int i = 0; i < N; i++)
        // {
        //     for (int j = 0; j < M; j++)
        //     {
        //         cout << map[i][j] << " ";
        //     }
        //     cout << endl;
        // }


        ++res_time;
        if (cur_total_cnt == 0) break;
    }
    
    cout << res_time << ":" << prev_cnt << endl;
    
    return 0;
}