#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef pair<long long, long long> l4;
typedef vector<long long> vll;
typedef double db;
typedef vector<double> vdb;
typedef pair<double, double> dd;
typedef set<int> si;
typedef set<long long> sll;
#define fi first
#define se second
#define matrix(a) vector< vector<a> >
#define sz(a) int((a).size()) 
#define lop(i,a,b) for (int i=a; i<=b; i++)
#define vlop(i,v) lop(i,0,sz(v)-1)
#define vlop1(i,v) lop(i,1,sz(v)-1)
#define rlop(i,a,b) for (int i=b; i>=a; i--)
#define vrlop(i,v) rlop(i,0,sz(v)-1)
#define vrlop1(i,v) rlop(i,1,sz(v)-1)
#define printv(i,v) vlop(i,v)cout<<v[i]<<" "
#define printv1(i,v) vlop1(i,v)cout<<v[i]<<" "
#define all(s) (s).begin(),(s).end()
#define pb push_back
#define enter cout<<'\n'
#define lb(i,v) int(lower_bound(all(v),i)-v.begin())
#define ub(i,v) int(upper_bound(all(v),i)-v.begin())

const int maxdigit = 31

class node {
public:
	node* left;
	node* right;
	int count;
	node() {
		left = nullptr;
		right = nullptr;
		count = 0;
	}
	bool empty() {
		return this->right == nullptr && this->left == nullptr && this->count == 0;
	}
	void add(ll n, int currentdigit) {
		if (!currentdigit) {
			(this->count)++;
			return;
		}
		if (n&(1LL << (currentdigit - 1))) {
			if (this->right == nullptr)this->right = new node();
			this->right->add(n, currentdigit - 1);
			return;
		}
		if (this->left == nullptr)this->left = new node();
		this->left->add(n, currentdigit - 1);
		return;
	}
	void remov(ll n, int currentdigit) {
		if (!currentdigit) {
			(this->count)--;
			return;
		}
		if (n&(1LL << (currentdigit - 1))) {
			this->right->remov(n, currentdigit - 1);
			if (this->right->empty()) {
				delete this->right;
				this->right = nullptr;
			}
			return;
		}
		this->left->remov(n, currentdigit - 1);
		if (this->left->empty()) {
			delete this->left;
			this->left = nullptr;
		}
		return;
	}
	ll maxxor(ll n, int currentdigit) {
		if (!currentdigit)return 0;
		if (n&(1LL << (currentdigit - 1))) {
			if (this->left != nullptr)return (1LL << (currentdigit - 1)) + this->left->maxxor(n, currentdigit - 1);
			return this->right->maxxor(n, currentdigit - 1);
		}
		if (this->right != nullptr) return (1LL << (currentdigit - 1)) + this->right->maxxor(n, currentdigit - 1);
		return this->left->maxxor(n, currentdigit - 1);
	}
};