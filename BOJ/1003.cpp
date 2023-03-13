#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int ones[40 + 1];
int zeros[40 + 1];

int main()
{
    memset(ones, -1, sizeof(ones));
    memset(zeros, -1, sizeof(zeros));
    ones[0] = 0; ones[1] = 1;
    zeros[0] = 1; zeros[1] = 0;
    for(int i=2;i<=40;i++){

        ones[i] = ones[i - 1] + ones[i - 2];
        zeros[i] = zeros[i - 1] + zeros[i - 2];
    }


    int T;
    cin >> T;

    int N;
    while(T--){

        cin >> N;

        cout << zeros[N] << ' ' << ones[N] << '\n';
    }

    return 0;
}