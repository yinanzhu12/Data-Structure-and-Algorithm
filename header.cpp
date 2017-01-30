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
#define last(a) a[sz(a)-1]
#define lop(i,a,b) for (int i=a; i<=b; i++)
#define vlop(i,v) lop(i,0,sz(v)-1)
#define rlop(i,a,b) for (int i=b; i>=a; i--)
#define printv(i,v) vlop(i,v)cout<<v[i]<<" "
#define all(s) (s).begin(),(s).end()
#define isthere(c,x) ((c).find(x) != (c).end()) 
#define cisthere(c,x) (find(all(c),x) != (c).end())
#define pb push_back
#define fill(s,v) memset(s,v,sizeof(s))

const long mod=1000000007;
const long double pi = acos(-1.0);

int main() {
	/* for reading .txt file
	ifstream infile;
	ofstream outfile;
	infile.open("input.txt");
	cin.rdbuf(infile.rdbuf());
	outfile.open("output.txt");
	cout.rdbuf(outfile.rdbuf());*/

	/*compute the power of two up to nth power mod 1000000007
	vi poweroftwo(1,1);
	lop(i,1,n){
		long t=poweroftwo[i-1];
		t=(t<<1)%mod;
		poweroftwo[i]=t;
	}*/
	/*compute the powerof ten up to nth power
	vi poweroften(1,1);
	lop(i,1,n)poweroften[i]=poweroften[i-1]*10;*/

	/*output with k digits after decimal
	cout<<setprecision(k)<<fixed;
	*/
	return 0;
}
