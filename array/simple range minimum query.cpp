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

using namespace std;

typedef vector<int> vi;
typedef vector<vi> matrix;
typedef pair<int, int> ii;
#define lop(i,a,b) for (int i=a; i<=b; i++)
#define rlop(i,a,b) for (int i=b; i>=a; i--)
#define trav(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define all(s) (s).begin(),(s).end()
#define isthere(c,x) ((c).find(x) != (c).end()) 
#define cisthere(c,x) (find(all(c),x) != (c).end())
#define pb push_back
#define fill(s,v) memset(s,v,sizeof(s))
#define sz(a) int((a).size())


int rmq(int i, int j,vi& a,vi& sectionmin) {
	int sqr = sqrt(sz(a));
	int start, end;
	start = i / sqr + (i%sqr == 0);
	end = j / sqr;
	min = a[i];
	lop(k, i, start*sqr)if (min > a[k])min = a[k];
	lop(k, start, end)if (min > sectionmin[k])min = sectionmin[k];
	lop(k,end*sqr,j)if (min > a[k])min = a[k];
	return min;
}

int main() {
	int n;
	cin >> n;
	vi a(n);
	lop(i,0,n-1)cin >> a[i];
	int sqr = sqrt(n);
	vi sectionmin;
	/*preprocess*/
	lop(i, 1, sqr ) {
		int min = a[i-1];
		lop(j, i, i - 1 + sqr) {
			if (a[j] < min)min = a[j];
		}
		sectionmin.pb(min);
	}
	if (sqr*sqr < n) {
		int min = a[sqr*sqr];
		lop(i, sqr*sqr, sz(a) - 1)if (a[i] < min)min = a[i];
		sectionmin.pb(min);
	}
	return 0;
}