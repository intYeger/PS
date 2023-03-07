#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

const double INF = 987654321;
int N, done;
pair<int, int> xy[16];
double W[16][16];
double cache[16][1<<16];

double tsp(int now, int state){

    if(state == done)
        return W[now][0];

    double& ret = cache[now][state];
    if(ret > -0.5) return ret;

    ret = INF;

    for(int next=0;next<N;next++){

        if(!(state & (1<<next)) && W[now][next]!=0){

            ret = min(ret, tsp(next, (state | (1 << next))) + W[now][next]);
        }
    }

    return ret;
}

int main()
{

    for(int i=0;i<16;i++)
        for(int j=0;j<(1<<16);j++)
            cache[i][j] = -1.0;

    cin>>N;

    done = (1 << N) - 1;

    int tmp_x, tmp_y;
    for(int i=0;i<N;i++){

        cin>>tmp_x>>tmp_y;
        xy[i] = make_pair(tmp_x, tmp_y);
    }

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){

            if(i == j) W[i][j] = 0;

            W[i][j] = sqrt((xy[i].first - xy[j].first) * (xy[i].first - xy[j].first)
                        + (xy[i].second - xy[j].second) * (xy[i].second - xy[j].second));
        }
            
    printf("%.6lf\n", tsp(0, 1));

    return 0;
}