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
#define rlop(i,a,b) for (int i=b; i>=a; i--)
#define all(s) (s).begin(),(s).end()
#define pb push_back
#define enter cout<<'\n'
#define lb(i,v) int(lower_bound(all(v),i)-v.begin())
#define ub(i,v) int(upper_bound(all(v),i)-v.begin())
const int inf = 1001;
const ll M = 1e9 + 7;
int k;

vll fact, invfact;

ll inverse(ll a, ll b) {
	vll r = { a,b };
	vll s = { 1,0 };
	while (true) {
		int i = sz(r) - 1;
		r.push_back(r[i - 1] % r[i]);
		ll q = r[i - 1] / r[i];
		s.push_back(s[i - 1] - s[i] * q);
		if (!r.back())break;
	}
	int i = sz(r) - 2;
	if (s[i]<0)s[i] += b;
	if (s[i] >= b)s[i] -= b;
	return s[i];
}
void factorio() {
	fact.resize(inf + 1, 1);
	invfact.resize(inf + 1, 1);
	lop(i, 1, inf) {
		fact[i] = fact[i - 1] * i%M;
		invfact[i] = euclidean(fact[i], M);
	}
	return;
}

ll comb(int a, int b) {
	return fact[a] * invfact[a - b] % M*invfact[b] % M;
}

/*use pascal's identity to compute 1^p+2^p+...+n^p for p=0,1,...,k*/
vll pascal(ll n) {
	if (!n)return 0;
	ll r = n, s0;
	vll s(k + 1);
	s[0] = n;
	lop(i, 1, k) {
		if ((n + 1) % M)r = ((r + 1)*(n + 1) + M - 1) % M;
		s0 = 0;
		lop(j, 0, i - 1)s0 = s0 + comb(i + 1, j)*s[j] % M;
		s[i] = (r - s0 + M) % M;
		s[i] = s[i] * inverse(i + 1, M) % M;
	}
	return s;
}