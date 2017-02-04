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
typedef long long ll;
typedef vector<long long> vll;
#define matrix(a) vector< vector<a> >
#define sz(a) int((a).size()) 
#define last(a) a[sz(a)-1]
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
#define fill(s,v) memset(s,v,sizeof(s))
#define enter cout<<endl;

const long M=1000000007;
const long double pi = acos(-1.0);

int main() {
	/* for reading .txt file
	ifstream infile;
	ofstream outfile;
	infile.open("input.txt");
	cin.rdbuf(infile.rdbuf());
	outfile.open("output.txt");
	cout.rdbuf(outfile.rdbuf());*/

	/*compute the power of two up to nth power mod M
	vi poweroftwo(n+1,1);
	lop(i,1,n)poweroftwo[i]=(long(poweroftwo[i-1])<<1)%M*/
	
	/*compute the powerof ten up to nth power
	vi poweroften(n+1,1);
	lop(i,1,n)poweroften[i]=poweroften[i-1]*10;*/
	
	/*compute factorio up to n mod M
	vi fact(n+1,1);
	lop(i,1,n)fact[i]=long(fact[i-1])*long(i)%M
	*/

	/*output with k digits after decimal
	cout<<setprecision(k)<<fixed;
	*/
	return 0;
}
