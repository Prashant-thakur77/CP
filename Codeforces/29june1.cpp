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
    ll n,c;
    cin>>n>>c;
    vector<ll> a(n);
    vector<ll> b(n);
    map<ll,ll> mp;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int yes=1;
    int ans=0;
    for(int i=0;i<n;i++){
        if(a[i]<b[i]){
            yes=0;
            break;
        }
        else{
            ans+=a[i]-b[i];
        }

    }
    sort(all(a));
    sort(all(b));
    int ans2=c;
    
    int yes2=1;
    for(int i=0;i<n;i++){
        
        if(a[i]>=b[i]){
            ans2+=a[i]-b[i];
        }
        else{
            yes2=0;
            break;

        }

        
        
    }
    if(yes==0 && yes2==0){
        cout<<-1<<endl;
    }
    else if(yes==0){
        cout<<ans2<<endl;
    }
    else{
        cout<<min(ans2,ans)<<endl;
    }

    
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