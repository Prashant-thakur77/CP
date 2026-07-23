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
class DSU{
    private:
    vector<int> parent,sz;
    int find(int x){
        if(parent[x]==x)return x;
        return parent[x]=find(parent[x]);
    }
    public:
    DSU(int n):parent(n),sz(n,1){
        iota(parent.begin(),parent.end(),0);
    }
    void unite(int a,int b){
        a=find(a);
        b=find(b);
        if(a==b)return;
        if(sz[a]<sz[b])swap(a,b);
        parent[b]=a;
        sz[a]+=sz[b];
    }
    bool same(int a,int b){
        return find(a)==find(b);
    }
};

void solve() {
    int n,x,y;
    cin>>n>>x>>y;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    DSU dsu(n);
    for(int i=0;i<n;i++){
        if(i+x<n){
            dsu.unite(i,i+x);

        }
        if(i+y<n){
            dsu.unite(i,i+y);
            
        }
    }
    for(int i=0;i<n;i++){
        int target=v[i]-1;
        if(!dsu.same(i,target)){
            cout<<"no"<<endl;
            return;
        }
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