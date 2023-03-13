#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n, k;
int values[100 + 1];
int cache[10000 + 1];

// int dp(int cur, int left){

//     if(left == 0) return 1;
//     else if(left < 0) return 0;

//     if(cur > n) return 0;

//     int& ret = cache[cur][left];
//     if(ret != -1) return ret;

//     ret = 0;

//     for(int i = 0; i<=(left/values[cur]);i++)
//         if(left >= i * values[cur])
//             ret += dp(cur + 1, left - i * values[cur]);

//     return ret;
// }

int main()
{
    memset(cache, 0, sizeof(cache));

    cin >> n >> k;
    for(int i=1;i<=n;i++)
        cin >> values[i];

    for(int cur = 1; cur<=n; cur++){

        for(int i = 0;i<=k;i++){

            int idx = 0;
            
            while(i + idx * values[cur] <= k){

                cache[i + idx * values[cur]] = cache[i] + 1;
                idx++;
            }
        }
            
    }

    cout<< cache[k] << endl;
    

    return 0;
}