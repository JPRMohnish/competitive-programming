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
void pre_processing(){}
//____________________________________😋Coding just for fun😋____________________________________________

double meet[6][6];
bool inf[10];
int v[10];
vin pos;

void infect(int j, vec<bool>& infm, double t1)
{
    loop(1, n+1, k)
    {
        if(k != j and infm[k] == false)
        {
            if(v[k] != v[j])
            {
                double t2 = (pos[j] - pos[k])/(v[k]-v[j]);
                if(t2 >= t1)
                {
                    infm[k] = true;
                    infect(k, infm, t2);
                }
            }
        }
    }
}


void solve()
{
    rd(n);
    loop(1, n+1, i)
    {
        cin >> v[i];
    }
    pos.clear();
    pos.push_back(0);
    if(n == 3)
        for(int i = 1; i < 4; i++)
            pos.push_back(i);
    else 
        for(int i = 1; i < 6; i++)
            pos.push_back(i);
    int mx = 0;
    int mn = 100;
    for(int i = 1; i <= n; i++)
    {
        vec<bool> infm(n+1, false);
        infm[i] = true;
        loop(1, n+1, j)
        {
            if(i != j and v[i] != v[j])
            {
                double t1 = (double)(pos[j]-pos[i])/(v[i]-v[j]);
                if(t1 >= 0)
                {
                    infm[j] = true;
                    infect(j, infm, t1);
                }
            }
        }
        int cnt = 0;
        for(int j = 1; j <= n; j++)
            if(infm[j] == true)
                cnt++;
        mx = max(mx, cnt);
        mn = min(mn, cnt);
    }
    cout << mn << " " << mx << endl;
}

int32_t main()
{
    fastio;
    pre_processing();
    w(true)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}