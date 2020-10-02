#include<iostream>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;
#define int long long

map<int, bool> found;
map<int, int> ans;

int fun(int n)
{
    if(found[n])
        return ans[n];
    int r = (n*(n+1))/2;
    if(r%2)
    {
        found[n] = true;
        ans[n] = 0; 
        return 0;
    }
    else
    {
        int a = ceil((sqrt(2*n*n-6*n+9)-1.0)/2.0);
        int b = floor((sqrt(2*n*n+2*n+1)-1.0)/2.0);
        r/=2;
        int cnt = 0;
        for(int x = a; x <= b; x++)
        {
            int j = r - x*(x+1)/2;
            if(j == 0)
            {
                cnt += ((x*(x-1))/2 + ((n-x-1)*(n-x))/2);
                
            }
            else 
                cnt += min(n-j, x) - max(x-j, 0LL); 
        }
        found[n] = true;
        ans[n] = cnt; 
        return cnt;
    }

}

int32_t main()
{
    int t;
    scanf("%lld", &t);
    while(t--)
    {
        int n;
        scanf("%lld", &n);
        n = fun(n);
        printf("%lld\n", n);
    }
}


// 1 2 3  4  5  6  7  8  9 10 11 12 | 13  14  15  16
// 1 3 6 10 15 21 28 36 45 55 66 78 | 91 105 120 136


// 39