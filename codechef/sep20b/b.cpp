#include<bits/stdc++.h>
using namespace std;

int arr[70][70];


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                cin >> arr[i][j];
        int ans = 0;
        bool transposed = false;
        for(int l = n; l > 1; l--)
        {
            // cout << "l " << l << endl;
            // cout << "tp " << transposed << endl;
            if(transposed)
            {
                if(arr[1][l] == l)
                {
                    ans++;
                    transposed ^= 1;
                }
            }
            else
            {
                if(arr[l][1] == l)
                {
                    ans++;
                    transposed ^= 1;
                }
            }
        }
        cout << ans << endl;
    }
}