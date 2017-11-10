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
#define rlop(i,a,b) for (int i=b; i>=a; i--)
#define printv(i,v) vlop(i,v)cout<<v[i]<<" "
#define all(s) (s).begin(),(s).end()
#define isthere(c,x) ((c).find(x) != (c).end()) 
#define cisthere(c,x) (find(all(c),x) != (c).end())
#define pb push_back
#define enter cout<<endl

/*read cumulative frequency of index i*/
template<typename T>
T cumfreq(int i,vector<T>& bitree) {
	T r = 0;
	while (i) {
		r += bitree[i];
		i -= (i&-i);
	}
	return r;
}

/*update the tree when the i-index element of marginal frequency list changed value by v, this function DO NOT update frequency list*/
template<typename T>
void updatetree(int i, int v, vector<T>& bitree) {
	while (i <sz(bitree)) {
		bitree[i] += v;
		i += (i&-i);
	}
	return;
}

/*cum=true if the frequency is cumulative*/
template<typename T>
void initialize(vector<T>& bitree, vector<T>& freq,bool cum) {
	bitree.resize(sz(freq),0);
	if (cum) {
		lop(i,1,sz(freq)-1){
			if(freq[i]-freq[i-1])update(i, freq[i] - freq[i - 1], bitree);
		}
		return;
	}
	lop(i,1,sz(freq)-1){
	        if(freq[i])update(i, freq[i], bitree);
	}
	return;
}

int main() {
	/*frequency list STARTs FROM 1,freq[0]=0,bitree starts off empty*/
	vi bitree,freq(n+1,0);
	initialize<int>(bitree, freq, true);
}
