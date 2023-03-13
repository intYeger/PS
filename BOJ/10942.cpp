#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int N;
int num[2000 + 1];
int M;
int cache[2000 + 1][2000 + 1];

int dp(int left, int right){

    if(left == right) return 1;
    if(right - left == 1){
        if(num[left] == num[right]) return 1;
        else return 0;
    }

    int& ret = cache[left][right];
    if(ret != -1) return ret;

    if(num[left] == num[right])
        ret = dp(left + 1, right - 1);
    else
        ret = 0;

    return ret;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(cache, -1, sizeof(cache));

    cin >> N;
    for(int i = 1;i<=N;i++)
        cin>>num[i];
    cin >> M;
    int S, E;
    for(int i = 1;i<=M;i++){
        cin >> S >> E;
        cout << dp(S, E)<< '\n';
    }

    return 0;
}