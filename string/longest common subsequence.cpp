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
#include <complex>

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

/*find the longest common subsequence of two string a,b*/
int main() {
	string a, b;
	int m = sz(a), n = sz(b);
	matrix(int) dp(m + 1, vi(n + 1, 0)),direction(m+1,vi(n+1,0));
	lop(i, 1,m) {
		lop(j, 1,n) {
			if (a[i - 1] == ar[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				direction[i][j] = 2; 
			}
			else if (dp[i][j - 1] > dp[i - 1][j]) {
				dp[i][j] = dp[i][j - 1];
				direction[i][j] = 1;
			}
			else dp[i][j] = dp[i - 1][j];
		}
	}
	/*direction=2 for pointing left-up, 1 for left, 0 for up*/
	string lcs;
	int p=m, q = n;
	while (p&&q) {
		if (direction[p][q] == 2) {
			lcs.append(1,a[p]);
			p--;
			q--;
		}
		else if (direction[p][q] == 1) q--;
		else p--;
	}
	reverse(all(lcs));
}
