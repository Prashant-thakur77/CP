#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define endl '\n'

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
ll v[200001];

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin>>n;
    vector<int> a(200001);
    int x=0;
    int y=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=a[i-1])x++;
        if(a[i]==a[i-1]+1)y++;
       
    }
    if(a[1]!=-1)cout<<v[n-x]<<endl;
    else cout<<(v[n-x]*y)%MOD<<endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        
        v[0]=1;
        for(int i=1;i<200001;i++){
            v[i]=(v[i-1]<<1)%MOD;

        }
        solve();
    }

    return 0;
}