#include <iostream>
#include <queue>
#include <tuple>


using namespace std;

int N;
int visited[300][300];
int start_c, start_r, end_r, end_c;
int cur_map_size;

int dr[8] = {1,2,2,1,-1,-2,-2,-1};
int dc[8] = {-2,-1,1,2,2,1,-1,-2};


void clear(int m) 
{
    for (int i = 0; i < m; ++i) {
        fill(visited[i], visited[i] + m, 0);
    }
}

void bfs(int r, int c) {
    
    visited[r][c] = 1;

    queue<tuple<int, int, int>> que;
    que.push({0,r,c});

    while(!que.empty()) 
    {
        tuple<int, int, int> front = que.front();
        int step = get<0>(front);
        int cur_r = get<1>(front);
        int cur_c = get<2>(front);
        que.pop();

        if (cur_r == end_r && cur_c == end_c) 
        {
            cout << step << endl;
            return;
        }

        for (int i = 0; i < 8; i++) 
        {
            int next_r = cur_r + dr[i];
            int next_c = cur_c + dc[i];

            if (next_r >=0 && next_c >= 0 && next_r < cur_map_size 
                && next_c < cur_map_size && visited[next_r][next_c] == 0) 
            {
                visited[next_r][next_c] = 1;
                int next_step = step + 1;
                que.push({next_step,next_r,next_c});
            }
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) 
    {
        cin >> cur_map_size >> start_r >> start_c >> end_r >> end_c;
        bfs(start_r, start_c);
        clear(cur_map_size);
    }


    return 0;
}