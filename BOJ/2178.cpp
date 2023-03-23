#include<iostream>
#include<string>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};

int N, M;
string matrix[100 + 1];
bool visited[100 + 1][100 + 1];

int bfs(){

    queue<pair<pair<int, int>, int> > q;

    q.push(make_pair(make_pair(0, 0), 0));
    visited[0][0] = true;

    while(!q.empty()){

        int y = q.front().first.first;
        int x = q.front().first.second;
        int times = q.front().second;
        q.pop();

        for(int d = 0; d < 4; d++){

            int nextY = y + dy[d];
            int nextX = x + dx[d];

            if(nextX < 0 || nextX >= M || nextY < 0 || nextY >= N) continue;
            if(visited[nextY][nextX] == true || matrix[nextY][nextX] == '0') continue;

            visited[nextY][nextX] = true;

            q.push(make_pair(make_pair(nextY, nextX), times + 1));

            if(nextY == N-1 && nextX == M-1) return (times + 1);
        }
    }

    return 0;
}

int main()
{
    memset(visited, false, sizeof(visited));

    cin >> N >> M;

    for(int i = 0; i < N; i++)
        cin >> matrix[i];

        
    cout << (bfs() + 1) << '\n';


    return 0;
}