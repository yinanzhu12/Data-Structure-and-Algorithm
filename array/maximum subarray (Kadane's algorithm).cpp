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
typedef long long ll;
typedef pair<long long, long long> l4;
typedef vector<long long> vll;
typedef double db;
typedef vector<double> vdb;
typedef pair<double, double> dd;
typedef set<int> si;
typedef set<long long> sll;
#define matrix(a) vector< vector<a> >
#define sz(a) int((a).size()) 
#define lop(i,a,b) for (int i=a; i<=b; i++)
#define rlop(i,a,b) for (int i=b; i>=a; i--)
#define all(s) (s).begin(),(s).end()
#define pb push_back
#define enter cout<<'\n'

template <typename T>
T maxsub(vector<T>& a, int l, int r) {
	T totalmax = a[l], closemax = a[l];
	lop(i, l + 1, r) {
		closemax = max(closemax + a[i], a[i]);
		totalmax = max(closemax, totalmax);
	}
	return totalmax;
}

int main() {
	vll a;
	maxsub(a, l, r);/*return the value of maximal sum of any subarray in a[l],a[l+1],...a[r]*/
}
