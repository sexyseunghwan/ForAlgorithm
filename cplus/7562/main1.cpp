#include <iostream>
#include <queue>

using namespace std;

int N;
int visited[300][300];
int step[300][300];

int dr[8] = {1,2,2,1,-1,-2,-2,-1};
int dc[8] = {-2,-1,1,2,2,1,-1,-2};

void clear(int m)
{
    for (int i = 0; i < m; i++) 
    {
        fill(visited[i], visited[i] + m, 0);
        fill(step[i], step[i] + m, 0);
    }
} 

void bfs(int cur_map, int start_r, int start_c, int target_r, int target_c)
{
    visited[start_r][start_c] = 1;
    queue<pair<int, int>> que;
    que.push({start_r, start_c});

    while(!que.empty())
    {
        int cur_r = que.front().first;
        int cur_c = que.front().second;
        que.pop();

        int route = step[cur_r][cur_c];

        if (cur_r == target_r && cur_c == target_c) 
        {
            cout << route << endl;
            return;
        }

        for (int i = 0; i < 8; i++) 
        {
            int next_r = cur_r + dr[i];
            int next_c = cur_c + dc[i];

            if (next_r >= 0 && next_c >= 0 && next_r < cur_map 
                && next_c < cur_map && visited[next_r][next_c] == 0) 
            {
                visited[next_r][next_c] = 1;
                que.push({next_r ,next_c});
                step[next_r][next_c] = route + 1;
            }

        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    while(N--)
    {
        int cur_map, start_r, start_c, target_r, target_c;
        cin >> cur_map >> start_r >> start_c >> target_r >> target_c;

        bfs(cur_map, start_r, start_c, target_r, target_c);
        clear(cur_map);
    }

    return 0;
}