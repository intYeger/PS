#include<iostream>
#include<algorithm>
using namespace std;

int N, M;
int A[1000000 + 1];
int B[1000000 + 1];
int result[2000000 + 1];

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N>>M;

    for(int i=0;i<N;i++)
        cin>>A[i];
    for(int i=0;i<M;i++)
        cin>>B[i];

    int cur_A = 0;
    int cur_B = 0;

    while(cur_A < N || cur_B < M){

        if(cur_A >= N){

            result[cur_A + cur_B] = B[cur_B];
            cur_B++;
        }
        else if(cur_B >= M){

            result[cur_A + cur_B] = A[cur_A];
            cur_A++;
        }

        else if(A[cur_A] > B[cur_B]){

            result[cur_A + cur_B] = B[cur_B];
            cur_B++;
        }
        else{

            result[cur_A + cur_B] = A[cur_A];
            cur_A++;
        }
    }

    for(int i=0;i<M+N;i++)
        cout<<result[i]<<' ';
    cout<<'\n';


    return 0;
}