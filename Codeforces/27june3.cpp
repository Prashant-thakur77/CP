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

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

void solve() {
    ll a,b,x;
    cin>>a>>b>>x;
    ll ans=INF;
    ll cnt=0;
    while(a!=b){
        if(b>a){
            swap(a,b);
        }
        ans=min(ans,abs(a-b)+cnt);
        a=a/x;
        cnt++;
    }
    ans=min(ans,cnt);
    cout<<ans<<endl;
    
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}