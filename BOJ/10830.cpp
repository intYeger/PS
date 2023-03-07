#include<iostream>
#include<vector>
using namespace std;

int N;
long long BB;
typedef long long ll;
typedef vector<vector<ll> > matrix;

matrix operator*(matrix& A, matrix& B){

    matrix tmp(N, vector<ll>(N));

    for(int i = 0;i<N;i++)
        for(int j = 0;j<N;j++){
            for(int k = 0;k<N;k++){
                tmp[i][j] += A[i][k]*B[k][j];
            }
            tmp[i][j] %= 1000;
        }

    
    return tmp;
}

matrix power(matrix A, ll n){

    if(n == 1){

        matrix a = A;
        for(int i = 0;i<N;i++)
            for(int j = 0;j<N;j++)
                a[i][j] %= 1000;
        return a;
    }

    // matrix res(N, vector<ll>(N));
    // for(int i = 0;i<N;i++)
    //     res[i][i] = 1;

    matrix a = power(A, ll(n/2));
    a = a * a;
    if(n % 2 == 1){

        return A * a;
    }
    else
        return a;
}

void print_matrix(matrix A){

    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){

            cout<<A[i][j]<<' ';
        }
        cout<<'\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>N>>BB;

    matrix origin(N, vector<ll>(N));

    for(int i = 0;i<N;i++)
        for(int j = 0;j<N;j++)
            cin>>origin[i][j];

    matrix ret = power(origin, BB);

    print_matrix(ret);

    return 0;
}