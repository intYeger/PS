#include<iostream>
#include<algorithm>
using namespace std;

const int INF = 987654321;
int N, done;
int W[16][16];
int cache[16][1<<16];

int tsp(int current, int state){

    if(state == done){

        if(W[current][0] == 0)
            return INF;
        else
            return W[current][0];
    }

    int& ret = cache[current][state];
    if(ret != 0) return ret;

    int tmp = INF;

    for(int next=0;next<N;next++){

        if(!(state & (1<<next)) && W[current][next] != 0){

            tmp = min(tmp, tsp(next, (state | (1 <<next))) + W[current][next]);
        }
    }

    return ret = tmp;
}

int main()
{

    cin>>N;

    done = (1 << N) - 1;

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>W[i][j];

    cout<< tsp(0, 1) << endl;


    return 0;
}