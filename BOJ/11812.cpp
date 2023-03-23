#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long N;
int K, Q;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> K >> Q;

    long long nodeA, nodeB;
    while(Q--){

        cin >> nodeA >> nodeB;

        if(K == 1){
            
            if(nodeA > nodeB) swap(nodeA, nodeB);
            cout << (nodeB - nodeA) << '\n';
            continue;
        }

        int ret = 0;
        
        while(nodeA != nodeB){

            if(nodeA > nodeB) swap(nodeA, nodeB);
            nodeB = (nodeB + K - 2) / K;
            ret++;
        }

        cout << ret << '\n';

        // node * K -> 뒤에서 두번째 (K -2)더해서 나누기
    }

    return 0;
}