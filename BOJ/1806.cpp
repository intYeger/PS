#include<iostream>
#include<algorithm>
using namespace std;

const int INF = 987654321;
int N, S;
int arr[100000 + 1];
int pSum[100000 + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> S;

    for(int i=0;i<N;i++){

        cin>>arr[i];
        if(i==0) pSum[i] = arr[i];
        else pSum[i] = pSum[i-1] + arr[i];
    }

    int left = 0;
    int right = 0;
    int m  = INF;

    int current_sum = pSum[0];

    while(right < N){

        if(current_sum < S){

            if(right == N-1) break;
            right++;
            current_sum += arr[right];
        }
        else{

            m = min(m, right-left+1);
            if(m == 1) break;
            current_sum -= arr[left];
            left++;
        }
    }

    if(m == INF) m = 0;

    cout<< m << endl;

    return 0;
}