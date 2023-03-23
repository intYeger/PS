#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

const int MAX = 50000 + 1;
int N, M;
vector<int> adj[MAX];
int parent[MAX];
int height[MAX];

void make_parent(int cur){

    for(int i = 0; i < adj[cur].size(); i++){

        int next = adj[cur][i];

        if(parent[next] != -1) continue;
        parent[next] = cur;
        height[next] = height[cur] + 1;
        make_parent(next);
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    memset(parent, -1, sizeof(parent));
    cin >> N;

    int a, b;
    for(int i = 0; i < N - 1; i++){

        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    parent[1] = 1;
    height[1] = 0;
    make_parent(1);

    cin >> M;
    for(int i = 0; i < M; i++){

        cin >> a >> b;

        if(height[a] > height[b]) swap(a, b);

        while(height[a] != height[b]){

            b = parent[b];
        }

        if(a == b) cout << a << '\n';
        else{

            while(a != b){

                a = parent[a];
                b = parent[b];
            }
            cout<< a << '\n';
        }

    }




    return 0;
}