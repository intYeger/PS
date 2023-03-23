#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;


int N;
int parent[10000 + 1];
int nodeA, nodeB;
bool visited[10000 + 1];

void dfs(int node){

    if(parent[node] == -1) return;

    visited[parent[node]] = true;
    dfs(parent[node]);

    return;
}

int find(int node){

    if(visited[node] == true) return node;

    if(parent[node] == -1) return -1;

    return find(parent[node]);
}

int main()
{

    int T;
    cin >> T;

    while(T--){

        memset(parent, -1, sizeof(parent));
        memset(visited, false, sizeof(visited));

        cin >> N;

        int A, B;
        for(int i = 0; i < N-1; i++){

            cin >> A >> B;
            parent[B] = A;
        }
        
        cin >> nodeA >> nodeB;

        visited[nodeA] = true;
        dfs(nodeA);

        cout << find(nodeB) << '\n';
    }

    return 0;
}