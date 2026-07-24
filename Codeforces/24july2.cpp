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
    ll n,k,m;
    cin>>n>>k>>m;
ll no=k-1;
    if(m<=no){
        cout<<"no"<<endl;
        return;
    }
    vector<ll> v(n);
    for(int i=0;i<k-1;i++){
        v[i]=1;

    }
    v[k-1]=m-(k-1);
    for(int i=k;i<n;i++){
        v[i]=1;
    }
    cout<<"yes"<<endl;
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

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