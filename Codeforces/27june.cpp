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
    ll n,k;
    cin>>n>>k;
    if(n<=k){
        cout<<n<<endl;
        return;
    }
    ll no=n/k;
    ll cursum=0;
    int no2=1;
    int l=0;
    while(no2<=no){
        
        if((1LL << l+1)-1>no){
            break;


        };
        l++;
        no2=pow(2,l)-1;
        

    }
    ll popcount=0;
    for(int i=0;i<k;i++){
        if(cursum+no>=(1LL << l+1)-1){
            popcount+=l+1;
            cursum=cursum+no-((1LL << l+1)-1);
        }
        else{
            popcount+=l;
            cursum+=no-no2;

        }
        
        


    }
    cout<<popcount<<endl;
    

    
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