#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

int w, h;
int ret;
int matrix[1000 + 1][1000 + 1];
bool visited[1000 + 1][1000 + 1];

void dfs(int curY, int curX){

    if(matrix[curY][curX] == 0) return;

    int ret = 0;
    visited[curY][curX] = true;

    for(int d = 0; d < 8; d++){

        int nextY = curY + dy[d];
        int nextX = curX + dx[d];

        if(nextY < 1 || nextY > h || nextX < 1 || nextX > w) continue;
        if(visited[nextY][nextX] == true || matrix[nextY][nextX] == 0) continue;

        dfs(nextY, nextX);
    }

    return;
}

int main()
{

    while(1){

        memset(visited, false, sizeof(visited));

        cin >> w >> h;
        if(w == 0 && h == 0) break;

        for(int i = 1; i <= h; i++)
            for(int j = 1; j <= w; j++)
                cin >> matrix[i][j];

        ret = 0;

        for(int i = 1; i <= h; i++)
            for(int j = 1; j<= w; j++)
                if(visited[i][j] == false && matrix[i][j] == 1){
                    dfs(i, j);
                    ret++;
                }

        cout << ret << '\n';
    }
    


    return 0;
}