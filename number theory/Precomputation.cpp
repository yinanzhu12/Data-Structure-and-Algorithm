#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <numeric>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<long> vl;
typedef long long ll;
typedef pair<long long, long long> llll;
typedef vector<long long> vll;
#define matrix(a) vector< vector<a> >
#define sz(a) int((a).size()) 
#define ite(v) v::iterator
#define lop(i,a,b) for (int i=a; i<=b; i++)
#define vlop(i,v) lop(i,0,sz(v)-1)
#define vlop1(i,v) lop(i,1,sz(v)-1)
#define rlop(i,a,b) for (int i=b; i>=a; i--)
#define vrlop(i,v) rlop(i,0,sz(v)-1)
#define vrlop1(i,v) rlop(i,1,sz(v)-1)
#define printv(i,v) vlop(i,v)cout<<v[i]<<" "
#define all(s) (s).begin(),(s).end()
#define isthere(c,x) ((c).find(x) != (c).end()) 
#define cisthere(c,x) (find(all(c),x) != (c).end())
#define pb push_back
#define enter cout<<endl

/*max number to compute series up to*/
const long long inf;

/*number to mod big number, if needed*/
const long long M;

ll euclidean(ll a, ll b) {
	vll r = { a,b };
	vll s = { 1,0 };
	while (true) {
		int i = sz(r) - 1;
		r.push_back(r[i - 1] % r[i]);
		ll q = r[i - 1] / r[i];
		s.push_back(s[i - 1] - s[i] * q);
		if (!r.back())break;
	}
	int i=sz(r)-2;
	if (s[i]<0)s[i] += b;
	if (s[i] >= b)s[i] -= b;
	return s[i];
}
void factorio(vll& fact,vll& invfact) {
	fact.resize(inf + 1, 1);
	invfact.resize(inf + 1, 1);
	vlop1(i, fact) {
		fact[i] = fact[i - 1] * i%M;
		invfact[i] = euclidean(fact[i], M);
	}
	return;
}

void powerof(int a, vll& power) {
	power.resize(inf + 1, 1);
	vlop1(i, power)power[i] = power[i - 1] * a%M;
	return;
}

int main() {
	/*fact[i]=i!%M, invfact[i]=(i!)^-1%M*/
	vll fact, invfact;
	factorio(fact, invfact);

	/*power[i]=a^i%M*/
	vll power;
	int a;
	powerof(a, power);
}
