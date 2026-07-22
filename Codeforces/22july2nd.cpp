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
    int n;
    cin>>n;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    if(n==1){
        cout<<"YES"<<endl;
        return;
    }
    int ok=1;
    for(int i=0;i<n-1;i++){
        if(v[i]<i+1){
            ok=0;
            break;
        }
        if(v[i]>=i+1){
            ll no=v[i]-(i+1);
            v[i+1]+=no;
            v[i]=i+1;
        }
    }
    if(v[n-1]<=v[n-2]){
        ok=0;
    }
    if(ok)cout<<"yes"<<endl;
    else cout<<"no"<<endl;
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