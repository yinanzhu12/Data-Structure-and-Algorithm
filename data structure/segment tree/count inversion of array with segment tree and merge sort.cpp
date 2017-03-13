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
#define enter cout<<'\n'

void initialize(int start, vector<llll>& stree, vi& a, int l, int u) {
	if (sz(stree) - 1<start)stree.resize(start + 1);
	if (l == u) {
		stree[start] = llll(0, 0);
		return;
	}
	initialize(2 * start, stree, a, l, (l + u) / 2);
	initialize(2 * start + 1, stree, a, (l + u) / 2 + 1, u);
	/*counting the number of normal and reversed pairs across section [l,(u+l)/2] and [(u+l)/2+1,u]*/
	ll nor = 0, rev = 0;
	int p = (l + u) / 2 + 1;
	lop(i, l, (l + u) / 2) {
		int ub = int(upper_bound(a.begin() + p, a.begin() + u + 1, a[i]) - a.begin());
		int lb = int(lower_bound(a.begin() + p, a.begin() + u + 1, a[i]) - a.begin());
		nor = nor + u - ub + 1;
		rev = rev + lb - (u + l) / 2 - 1;
		p = lb;
	}
	/*merge sort section [l,u], since [l,(u+l)/2] and [(u+l)/2+1,u] are already sorted*/
	vi at(u - l + 1);
	int p1 = l, p2 = (l + u) / 2 + 1;
	lop(i, l, u) {
		if (p1 <= (l + u) / 2 && p2 <= u) {
			if (a[p1]<a[p2]) {
				at[i - l] = a[p1];
				p1++;
			}
			else {
				at[i - l] = a[p2];
				p2++;
			}
		}
		else if (p1>(l + u) / 2) {
			at[i - l] = a[p2];
			p2++;
		}
		else {
			at[i - l] = a[p1];
			p1++;
		}
	}
	copy(all(at), a.begin() + l);
	stree[start] = llll(nor, rev);
	return;
}

int main() {
	int n;
	cin >> n;
	vi a(1 << n);
	vlop(i, a)cin >> a[i];
	vector<llll> stree, level(n, llll(0, 0));
	initialize(1, stree, a, 0, sz(a) - 1);
	/*store the total number of normal and reversed pairs in each level of tree*/
	vlop(i, level) {
		lop(j, (1 << i), (1 << i + 1) - 1) {
			level[i].first += stree[j].first;
			level[i].second += stree[j].second;
		}
	}
	return 0;
}