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
typedef pair<long long, long long> llll;
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
#define enter cout<<endl

void failure(vi& f, string& s) {
	lop(i, 1, sz(s) - 1) {
		int t = last(f);
		while (true) {
			if (s[i] == s[t]) {
				f.pb(t + 1);
				break;
		}
			else if(!t){
				f.pb(0);
				break;
			}
			else t = f[t-1];
		}

	}
	return;
}

int main(){
	string s;
	vi f={0};
	/*compute failure function*/
	failure(f, s);
}
