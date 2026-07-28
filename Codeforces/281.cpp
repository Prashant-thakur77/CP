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
    int cnt1=0;
    int flag=0;
    int cnt12=0;
    int right=-1;
    for(int i=0;i<n-2;i++){
        if(v[i]==1 && flag==0){
            cnt1++;
            int no=i+1;
            if(2*cnt1>no && i+1<n-2 && v[i+1]==3){
                right=i+1;
                break;
            }
            else if(2*cnt1>=no){
                right=i;
                break;
            }
            
        }
    }
    if(right==-1){
        cout<<"no"<<endl;
        return;
    }
    int right2=-1;
    for(int i=right+1;i<n-1;i++){
        if(v[i]==1 || v[i]==2){
            cnt12++;
            int no=i-right;
            if(2*cnt12>=no){
                right2=i+1;
                break;
            }


        }

    }
    if(right2==-1){
        cout<<"no"<<endl;
        return;

    }
    cout<<"yes"<<endl;

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