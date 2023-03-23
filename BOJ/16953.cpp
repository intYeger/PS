#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

long long A, B;

int bfs(){

    queue<long long> q;
    q.push(A);

    int ret = 0;

    while(!q.empty()){

        int curSize = q.size();
        ret++;

        for(int i = 0; i < curSize; i++){

            long long cur = q.front();
            q.pop();
            if(cur == B) return ret;

            if(cur * 2 <= B){

                q.push(cur * 2);
            }
            if(cur * 10 + 1 <= B){

                q.push(cur * 10 + 1);
            }
        }
    }

    return -1;
}

int main()
{

    cin >> A >> B;

    cout << bfs() << '\n';

    return 0;
}