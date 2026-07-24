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
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    if(n%2!=0){
        cout<<"no"<<endl;
        return;
    }
    if(n==1){
        cout<<"no"<<endl;
        return;

    }
    if(n==2){
        if(v[0]+v[1]==0){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
        return;
    }
    int no=0;
    for(int i=0;i<n;i++){
        no+=v[i];
    }
    if(no%4==0){
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