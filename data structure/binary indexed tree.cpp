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

/*read cumulative frequency of index i*/
int cumfreq(int i,vi& bitree) {
	int r = 0;
	while (i) {
		r += bitree[i];
		i -= (i&-i);
	}
	return r;
}

/*update the tree when the i-index element of marginal frequency list changed value by v, this function DO NOT update frequency list*/
void updatetree(int i, int v, vi& bitree) {
	while (i <sz(bitree)) {
		bitree[i] += v;
		i += (i&-i);
	}
	return;
}

/*cum=true if the frequency is cumulative*/
void initialize(vi& bitree, vi& freq,bool cum) {
	bitree.resize(sz(freq));
	if (cum) {
		update(0, freq[0], bitree);
		vlop1(i, freq)update(i, freq[i] - freq[i - 1], bitree);
		return;
	}
	vlop(i, freq) update(i, freq[i], bitree);
	return;
}

int main() {
	/*frequency list STARTs FROM 1,freq[0]=0,bitree starts off empty*/
	vi bitree,freq(n+1,0);
	initialize(bitree, freq, true);
}