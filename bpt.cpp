#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

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

ll d, t;

class BPTnode{
	public:
		vector<ll> key;
		vector<BPTnode*> ptr;
		bool isLeaf;
		BPTnode* next;
		BPTnode* prev;
		BPTnode* par;
		BPTnode(){
			key={};
			ptr={};
			isLeaf=false;
			next=NULL;
			prev=NULL;
			par=NULL;
		}
};

class BPT{
	public:
		ll nd, ni;
		BPTnode* root;
		BPT(){
			root=new BPTnode();
			root->isLeaf=true;
			nd=1;ni=0;
		}
		void BPTsplit(BPTnode* x){
			// debug(x->key,x->isLeaf);
			if (x->isLeaf){
				nd++;
				ll sep=(x->key)[d];
				BPTnode* a=new BPTnode();
				BPTnode* b=new BPTnode();
				a->isLeaf=true;
				b->isLeaf=true;
				for (ll i=0; i<d; i++){
					(a->key).push_back((x->key)[i]);
				}
				for (ll i=d; i<=2*d; i++){
					(b->key).push_back((x->key)[i]);
				}
				if (x->par==NULL){
					// debug(x->key);
					ni++;
					BPTnode* temp=new BPTnode();;
					root=temp;
					(root->key).push_back(sep);
					a->par=root;b->par=root;
					(root->ptr).push_back(a);
					(root->ptr).push_back(b);
				}
				else{
					BPTnode* p=x->par;
					// debug(p->key);
					ll n=(p->ptr).size();
					ll in=-1;
					vector<BPTnode*> temp;
					for (ll i=0; i<n; i++){
						if ((p->ptr)[i]==x){
							in=i;break;
						}
					}
					for (ll i=0; i<in; i++) temp.push_back((p->ptr)[i]);
					temp.push_back(a);temp.push_back(b);
					for (ll i=in+1; i<n; i++) temp.push_back((p->ptr)[i]);
					p->ptr=temp;
					a->par=p;b->par=p;
					(p->key).push_back(sep);
					sort((p->key).begin(),(p->key).end());
					if ((p->key).size()>2*t+1) BPTsplit(p);
				}
			}
			else{
				ni++;
				BPTnode* a=new BPTnode();
				BPTnode* b=new BPTnode();
				BPTnode* p=x->par;
				ll y=(x->key)[t];
				for (ll i=0; i<t; i++){
					(a->key).push_back((x->key)[i]);
				}
				for (ll i=t+1; i<2*t+2; i++){
					(b->key).push_back((x->key)[i]);
				}
				for (ll i=0; i<=t; i++){
					(a->ptr).push_back((x->ptr)[i]);
					((x->ptr)[i])->par=a;
				}
				for (ll i=t+1; i<=2*t+2; i++){
					(b->ptr).push_back((x->ptr)[i]);
					((x->ptr)[i])->par=b;
				}
				if (p==NULL){
					// debug(x->key);
					ni++;
					BPTnode* temp=new BPTnode();;
					root=temp;
					(root->key).push_back(y);
					a->par=root;b->par=root;
					(root->ptr).push_back(a);
					(root->ptr).push_back(b);
				}
				else{
					ll n=(p->ptr).size();
					ll in=-1;
					vector<BPTnode*> temp;
					for (ll i=0; i<n; i++){
						if ((p->ptr)[i]==x){
							in=i;break;
						}
					}
					for (ll i=0; i<in; i++) temp.push_back((p->ptr)[i]);
					temp.push_back(a);temp.push_back(b);
					for (ll i=in+1; i<n; i++) temp.push_back((p->ptr)[i]);
					p->ptr=temp;
					a->par=p;b->par=p;
					// debug(p->key);
					(p->key).push_back(y);
					sort((p->key).begin(),(p->key).end());
					if ((p->key).size()>2*t+1) BPTsplit(p);
				}
			}
		}
		void BPTinsertval(BPTnode* x, ll val){
			// debug(root->key);
			// debug(x->key);
			if (x->par!=NULL) {
				// debug((x->par)->key);
			}
			if (!x->isLeaf){
				auto it=lower_bound((x->key).begin(),(x->key).end(),val);
				ll in=it-(x->key).begin();
				BPTinsertval((x->ptr)[in],val);
			}
			else{
				// debug(x->key);
				if ((x->key).size()==2*(d)){
					(x->key).push_back(val);
					sort((x->key).begin(),(x->key).end());
					BPTsplit(x);
				}
				else {
					(x->key).push_back(val);
					sort((x->key).begin(),(x->key).end());
				}
			}
		}
		void BPTprint(){
			// cout<<ni<<" "<<nd<<" ";
			for (auto u: root->key) cout<<u<<" ";
			// cout<<endl;
		}
		pair<ll,ll> BPTcount(BPTnode* x, ll ci, ll cd){
			debug(x->key,x->isLeaf);
			if (x->isLeaf) cd++;
			else{
				ci++;
				for (auto u: x->ptr){
					pair<ll,ll> z=BPTcount(u,0ll,0ll);
					ci+=z.F;
					cd+=z.S;
				}
			}
			return {ci,cd};
		}
};

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // for getting input frm input.txt
    freopen("output.txt", "w", stdout);
    // for getting output frm output.txt
    #else
    #endif
	cin>>d>>t;
	ll x;
	ll fl=0;
	BPT tree;
	while (cin>>x){
		if (x==1){
			fl=1;
			ll y;
			cin>>y;
			// debug(y);
			tree.BPTinsertval(tree.root,y);
		}
		else if (x==2){
			debug(true);
			pair<ll,ll> a=tree.BPTcount(tree.root,0,0);
			// if (fl) tree.BPTprint();
			// else cout<<0<<" "<<0<<endl;
			if (fl==0) cout<<"0 0";
			else cout<<a.F<<" "<<a.S<<" ";
			tree.BPTprint();
			cout<<endl;
		}
		else break;
	}
	return 0;
}
