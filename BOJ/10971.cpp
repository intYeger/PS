#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int INF = 987654321;
int N;
int W[10+1][10+1];

int tsp(vector<int>& path, vector<bool>& visited, int cost){

    if(path.size() == N){

        if(W[path.back()][1] != 0)
            return cost + W[path.back()][1];
        else return INF;
    }

    int ret = INF;

    for(int i = 1;i<=N;i++){

        if(visited[i] == false && W[path.back()][i] != 0){

            int last = path.back();
            path.push_back(i);
            visited[i] = true;
            ret = min(ret, tsp(path, visited, cost+W[last][i]));
            path.pop_back();
            visited[i] = false;
        }
    }

    return ret;
}

int main()
{

    cin>>N;
    for(int i = 1;i<=N;i++)
        for(int j = 1;j<=N;j++)
            cin>>W[i][j];

    vector<int> path;
    path.push_back(1);

    vector<bool> visited;
    visited.resize(N + 1);
    visited[1] = true;

    cout<< tsp(path, visited, 0) <<endl;


    return 0;
}