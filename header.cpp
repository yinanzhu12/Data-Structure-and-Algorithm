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
typedef pair<int, int> ii;
typedef vector<long> vl;
#define matrix(a) vector< vector<a> >
#define sz(a) int((a).size()) 
#define lop(i,a,b) for (int i=a; i<=b; i++)
#define vlop(i,v) lop(i,0,sz(v)-1)
#define rlop(i,a,b) for (int i=b; i>=a; i--)
#define printv(i,v) vlop(i,v)cout<<v[i]<<" "
#define all(s) (s).begin(),(s).end()
#define isthere(c,x) ((c).find(x) != (c).end()) 
#define cisthere(c,x) (find(all(c),x) != (c).end())
#define pb push_back
#define fill(s,v) memset(s,v,sizeof(s))


const long double pi = acos(-1.0);


int main() {
	/* for reading .txt file
	ifstream infile;
	ofstream outfile;
	infile.open("input.txt");
	cin.rdbuf(infile.rdbuf());
	outfile.open("output.txt");
	cout.rdbuf(outfile.rdbuf());*/

	/*compute the power of two up to nth power
	vi poweroftwo(1,1)
	lop(i,1,n)poweroftwo[i]=(poweroftwo[i-1]<<1);
	*/

	/*for multiple test case
	int t;
	cin >> t;
	lop(testcase, 1, t) {

	}*/

	/*output with k digits after decimal
	cout<<setprecision(k)<<fixed;
	*/
	return 0;
}
