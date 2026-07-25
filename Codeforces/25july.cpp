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
    vector<int> a(n);
    vector<int> b(n);
    int cnt0=0;
    int cnt0b=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==0)cnt0++;
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
        if(b[i]==0)cnt0b++;
    }
    if(cnt0 && cnt0b==0 || cnt0==n && cnt0b!=n){
        cout<<-1<<endl;
        return;
    }
    int ok=1;
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            ok=0;
            break;
        }
    }
    if(ok){
        cout<<0<<endl;
        return;
    }
    ok=0;
    
    for(int i=0;i<n;i++){
       
    
        if(a[i]==1-b[i]){
            
            ok+=a[i];
        
        }

    }
    if(ok%2){
        cout<<1<<endl;
    }
    else cout<<2<<endl;
    

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