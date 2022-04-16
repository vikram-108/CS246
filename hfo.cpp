#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll MOD=((1e9)+7);
const ll INF=1e18;

#define F first
#define S second

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // for getting input frm input.txt
    freopen("output.txt", "w", stdout);
    // for getting output frm output.txt
    #else
    #endif
    vector<pair<vector<pair<ll,ll>>,pair<ll,ll>>> p;
    p.push_back({{},{0,16}});
    ll si;
    cin>>si;
    // debug(si);
    ll x;
    ll fl2=0;
    while (cin>>x){
        if (x==1){
            fl2=1;
            ll a, b;
            cin>>b>>a;
            // debug(a,b);
            ll fl=0;
            for (auto &u: p){
                if (b+4+u.S.S<=si){
                    u.F.push_back({a,b});
                    u.S.F++;
                    // debug(u.S.F);
                    u.S.S+=b+4;
                    fl=1;break;
                }
            }
            if (fl==0){
                p.push_back({{{a,b}},{1,20+b}});
            }
        }
        else if (x==2){
            if (fl2==0) cout<<0<<endl;
            else{
                cout<<p.size()<<" ";
                for (auto u: p){
                    // debug(u.S);
                    cout<<u.S.F<<" ";
                }
                cout<<endl;
            }
        }
        else if (x==3){
            ll y;
            cin>>y;
            ll fl=0;
            for (ll i=0; i<p.size(); i++){
                for (ll j=0; j<p[i].F.size(); j++){
                    if ((((p[i].F)[j]).F)==y){
                        cout<<i<<" "<<j<<endl;
                        fl=1;
                        break;
                    }
                }
                if (fl) break;
            }
            if (fl==0) cout<<"-1 -1"<<endl;
        }
        else break;
    }
    return 0;
}
