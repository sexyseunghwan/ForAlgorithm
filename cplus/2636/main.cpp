#include <iostream>

using namespace std;

int N,M;
int map[100][100];
int visited[100][100];
int cheese_cnt;
int res_time;
int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};
int prev_cnt;
int cur_total_cnt;

// void dfs(int cur_r, int cur_c)
// {
//     //visited[cur_r][cur_c] = 1;
//     //--cur_total_cnt;
    
//     //for ()

//     // for (int i = 0; i < 4; i++)
//     // {
//     //     int next_r = cur_r + dr[i];
//     //     int next_c = cur_c + dc[i];

//     //     if (next_r >= 0 && next_c >= 0 && next_r < N && next_c < M && visited[next_r][next_c] == 0 && map[next_r][next_c] == 1)
//     //     {   
//     //         map[next_r][next_c] = 0;
//     //         dfs(next_r, next_c);
//     //     }
//     // }
// }

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> N >> M;

    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            int input;
            cin >> input;
            if (input == 1) ++prev_cnt;
            map[i][j] = input;
        }
    }
    
    cur_total_cnt = prev_cnt;
    bool flag = true;

    while(flag)
    {

        prev_cnt = cur_total_cnt;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (map[i][j] != 0)
                {
                    //dfs(i,j);
                }
            }
        }
        
        ++res_time;
        if (cur_total_cnt == 0) break;
    }
    

    cout << res_time << ":" << prev_cnt << endl;
    
    return 0;
}