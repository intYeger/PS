#include<iostream>
#include<algorithm>
using namespace std;

int N, K;
int temperature[100000 + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N>>K;
    for(int i=1;i<=N;i++)
        cin>>temperature[i];

    int left = 1;
    int right = K;
    int psum = 0;

    for(int i=1;i<=K;i++)
        psum += temperature[i];
    int ret = psum;

    while(right <= N){

        ret = max(ret, psum);
        psum -= temperature[left++];
        psum += temperature[++right];
    }

    cout << ret << endl;


    return 0;
}