#include <iostream>
#include <string>

using namespace std;

int N,M;
char map[600][600];
bool visited[600][600];
int meet_cnt;
int my_r;
int my_c;
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};

void dfs(int r, int c)
{
    visited[r][c] = true;

    if (map[r][c] == 'P') meet_cnt++;

    for (int i = 0; i < 4; i++) {
        int next_r = r + dr[i];
        int next_c = c + dc[i];

        if (next_r >= 0 && next_c >= 0 && next_r < N && next_c < M 
            && !visited[next_r][next_c] && map[next_r][next_c] != 'X') {
            dfs(next_r, next_c);
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        string inputs;
        cin >> inputs;
        
        for (int j = 0; j < M; j++) {
            char input = inputs[j];
            
            if (input == 'I') {
                my_r = i;
                my_c = j;
            }
            
            map[i][j] = input;
        }
    }
    
    dfs(my_r, my_c);
    
    if (meet_cnt == 0) {
        cout << "TT" << endl;
    } else {
        cout << meet_cnt << endl;
    }
    
    return 0;
}