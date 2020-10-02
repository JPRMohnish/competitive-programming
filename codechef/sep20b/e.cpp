#include<bits/stdc++.h>
using namespace std;
#define int long long

int twos[30];

int32_t main()
{
    twos[0] = 1;
    for(int i = 1; i < 25; i++)
        twos[i] = twos[i-1]*2;
    
    int qu;
    cin >> qu;
    while(qu--)
    {
        int n;
        cin >> n;
        int ans = 0;
        for(int i = 0; i < 10; i++)
        {
            int j = (twos[i+1] + twos[i+11]);
            cout << 1 << " " << j << endl << flush;
            cin >> j;
            
            int t = (twos[i] + twos[i+10] + twos[i+1] + twos[i+11]);
            cout << 1 << " " << t << endl << flush;
            cin >> t;
            
            t = j-t;
            t += ((twos[i] + twos[i+10])*n);
            t /= 2;
            int t1 = t%(twos[i+10]);
            int t2 = t-t1;
            t1 /= (twos[i]);
            t2 /= (twos[i+10]);
            // cout << "i: " << i << endl;
            // cout << i << "th " << t1 << " " <<  i+10 <<"th " << t2 << endl;
            if(t1%2 == 1)
                ans += twos[i];
            if(t2%2 == 1)
                ans += twos[i+10];    
        }
        cout << 2 << " " << ans << endl;
        int gbg;
        cin >> gbg;
    }
}