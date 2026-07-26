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
    for(int i=0;i<n;i++)cin>>v[i];
    int ok=1;
    ll no1=INT_MAX;
    ll no2=INT_MIN;
    for(int i=0;i<n-1;i+=2){
            no1=min(no1,v[i]);
            no2=max(no2,v[i+1]);
        
    }
    //cout<<no1<<" "<<no2<<endl;
    if(n%2==1){
        cout<<"no"<<endl;
        return;
    }
    if(no1>no2+1){
        cout<<"yes"<<endl;
    }
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