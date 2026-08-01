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
    string s;
    cin>>s;
    int n=s.length();
    bool flag1=false;
    bool flag2=false;
    string ans="";

    for(int i=0;i<n;i++){
        if(s[i]=='1' && !flag1){
            flag1=true;
            continue;
        }
        if(s[i]=='0' && !flag2){
            flag2=true;
            continue;
        }

        ans+=s[i];
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