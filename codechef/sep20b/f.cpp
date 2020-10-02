#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define int long long int
using namespace std;
#define pii pair <int, int>
#define mii map<int, int>
#define pb push_back
#define deb(x) cout << #x << " " << x << endl;
#define deb2(x, y) cout << #x << " " << x << " " << #y << " " << y << endl;
#define pt(a) cout << a << endl;
#define ptt(a, b) cout << a << " " << b << endl;
#define ptf(a) cout << a << " ";
#define rd(a) cin >> a;
#define rdd(a, b) cin >> a >> b;
#define loop(s, e, itr) for (int itr = s; itr < e; itr++)
#define lop(n) for(int i = 0; i < n; i++)
#define lopj(n) for(int j = 0; j < n; j++)
#define lopk(n) for(int k = 0; k < n; k++)
#define vin vector<int>
#define w(flag) int tc = 1; if(flag) cin >> tc; for(int t = 1; t <= tc; t++)
#define vec vector
#define mod 1000000007
#define all(x) x.begin(), x.end()
#define elif else if
#define nline cout << endl;
//_________________________________😌😌 SAB MOH MAYA HAI😌😌____________________________________________







int ar[1000006] = {0};
int n = 0;
int tp(0), tp1(0), tp2(0), tp3(0), tp4(0);
string str;
int len;

int power(int a, int p, int md = 1000000007){
    int ans = 1;
    while(p){
        if(p&1) ans = (ans*a)%md;
        a = (a*a)%md;
        p >>= 1; 
    }
    return ans;
}

int fact[100010];
int factInv[100010];

void pre_processing(){
    fact[1] = 1;
    fact[0] = 0;
    for(int i = 2; i < 100010; i++)
        fact[i] = (fact[i-1]*i)%mod;

    for(int i = 0; i < 100010; i++)
        factInv[i] = power(fact[i], mod-2)%mod;    
}
//____________________________________😋Coding just for fun😋____________________________________________

int ncr(int N, int R)
{
    if(R == 0)
        return 1;
    if(N == R)
        return 1;
    int a = fact[N]%mod;
    int b = factInv[R]%mod;
    int c = factInv[N-R]%mod;
    a = (a*b)%mod;
    a = (a*c)%mod;
    return a;
}



void solve()
{
    rd(n)
    lop(n)
        rd(ar[i])
    sort(ar, ar+n);
    int mx = ar[n-1];
    int z = 0;
    lop(n)
        if(ar[i] < mx)
            z++;
        else
            break;
    int nz = n-z;
    if(nz%2 == 0)
    {
        nz = (power(2,nz)-ncr(nz,nz/2)+mod)%mod;
    }
    else
    {
        nz = power(2,nz)%mod;
    }      
    z = power(2, z);
    int ans = (z*nz)%mod;
    cout << ans << endl;
}

int32_t main()
{
    pre_processing();
    fastio;
    w(true)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}

// 1 2 3 4 5 6 7 8 9
// 21   
// 45