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
    int n,k;
    cin>>n>>k;
    if(k>n-2){
        cout<<-1<<endl;
        return;
    }
    string s="";
    int cnt=0;
    int no=k/2 +1;
    int no2=0;
    if(k%2==0){
        no2=no;

    }
    else no2=no+1;
    while(cnt<no){
        s+="1";
        cnt++;
        
    }
    cnt=0;
    while(cnt<no2){
        s+="0";
        cnt++;
        
    }
    int start=s.length();
    

    for(int i=start;i<n;i++){
        if(i>0 &&s[i-1]=='0'){
            s+="1";
        }
        else s+="0";
        
    }
    cout<<s<<endl;


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