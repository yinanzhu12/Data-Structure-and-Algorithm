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
#define lop(i,a,b) for (int i=a; i<=b; i++)
#define rlop(i,a,b) for (int i=b; i>=a; i--)
#define all(s) (s).begin(),(s).end()
#define pb push_back
#define enter cout<<endl

/*max number to compute series up to*/
const int inf;

/*number to mod big number, if needed*/
const long long M;

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
	int i=sz(r)-2;
	if (s[i]<0)s[i] += b;
	if (s[i] >= b)s[i] -= b;
	return s[i];
}
void factorio() {
	fact.resize(inf + 1, 1);
	invfact.resize(inf + 1, 1);
	lop(i,2, inf) {
		fact[i] = fact[i - 1] * i%M;
		invfact[i] = inverse(fact[i], M);
	}
	return;
}

ll comb(int a, int b) {
	if(a<0||b<0||a<b) return 0;
	return fact[a] * invfact[a - b] % M*invfact[b] % M;
}

ll perm(int a, int b) {
	if(a<0||b<0||a<b) return 0;
	return fact[a] * invfact[a - b] % M;
}

int main() {
	/*fact[i]=i!%M, invfact[i]=(i!)^-1%M*/
	factorio();
	
	/*a!/(b!(a-b)!)*/
	comb(a, b);

	/*a!/(a-b)!*/
	perm(a, b);
}
