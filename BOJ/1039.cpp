#include<iostream>
#include<string>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

string N;
int K;
bool visited[1000000 + 1];

int bfs(){

    queue<string> q;

    int cnt = 0;
    int ret = 0;

    q.push(N);

    while(!q.empty()){

        int qsize = q.size();
        cnt++;
        memset(visited, false, sizeof(visited));

        if(cnt > K){

            if(ret == 0) return -1;
            return ret;
        }

        while(qsize--){

            string nowN = q.front();
            q.pop();
            
            for(int i = 0; i < nowN.size(); i++){

                for(int j = i + 1; j < nowN.size(); j++){

                    string tmpN = nowN;
                    swap(tmpN[i], tmpN[j]);

                    if(tmpN[0] == '0') continue;

                    int numN = stoi(tmpN);
                    if(visited[numN] == true) continue;

                    q.push(tmpN);
                    visited[numN] = true;

                    if(cnt == K)
                        ret = max(ret, numN);
                }
            }
        }
    }
    
    return -1;
}

int main()
{

    memset(visited, false, sizeof(visited));
    cin >> N >> K;

    cout << bfs() << '\n';

    return 0;
}