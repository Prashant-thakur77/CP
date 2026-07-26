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
    vector<int> a(n),b(n),c(n),d(n);
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    }
    int ans=0;
    for(int i=n;i>=1;i--){         
        int pos=1;                        
        for(int j=0;j<n && pos<=i;j++){
            if(pos >= a[j] && pos<=b[j]) continue;  
            int r=i- pos + 1;
            if(r >= c[j] && r <= d[j]) continue;   
            pos++;                                     
        }
        if(pos == i+1){ 
            ans=i; 
            break; 
        }
    }
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