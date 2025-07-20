#include <iostream>

using namespace std;

int N,M;
int map[100][100];
int visited[100][100];
int cheese_cnt;
int time;

void dfs(int r, int c)
{

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> N >> M;

    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            cin >> map[i][j];
        }
    }
    
    bool flag = true;

    while(flag)
    {
        
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] != 0)
            {
                dfs(i,j);
            }
        }
    }


    return 0;
}