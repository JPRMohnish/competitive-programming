#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        set<int> st;
        for(int i = 0; i < n; i++)
        {
            int tp;
            cin >> tp;
            if(tp != 0)
                st.insert(tp);
        }
        cout << st.size() << endl;
    }
}