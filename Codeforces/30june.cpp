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
    int x,y;
    cin>>x>>y;
    map<int,int> mp;
    for(int i=2;i<=x;i++){
        while(x%i==0){
            mp[i]++;
            x=x/i;
            

        }
    }
     map<int,int> mp2;
    for(int i=2;i<=y;i++){
        while(y%i==0){
            mp2[i]++;
            y=y/i;
            

        }
    }
    int ans=1;
    for(auto& it:mp2){
        int no=it.first;
        if(mp[no]<it.second){
            ans=0;
            break;

        }
    }
    if(ans){
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