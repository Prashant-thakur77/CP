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

    string s;
    cin>>s;

    int ans=1,x=0;

    for(int i=1;i<n;i++){
        if(s[i]!=s[i-1])
            ans++;
        if(i==n-1)
            break;
        if(s[i]!=s[i-1]&&s[i]!=s[i+1]){
            if(s[i+1]==s[i-1])
                x=2;
            else x=max(x,1);
        }
    }

    cout<<ans-x<<endl;
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