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


using namespace std;

/*determine the alphabet needed to deal with*/
const char start = 'a';
const int range = 26;

class trie {
public:
	int words;
	int prefixes;
	vector<trie*> edges;
	trie() {
		words = 0;
		prefixes = 0;
		edges = vector<trie*>(range, nullptr);
	}
	void add(string& s,int pos) {
		if (pos==sz(s)) {
			this->words += 1;
			return;
		}
		this->prefixes += 1;
		int c = s[pos] - start;
		if (this->edges[c] == nullptr) this->edges[c] = new trie;
		this->edges[c]->add(s,pos+1);
		return;
	}
	int countword(string& s,int pos) {
		if (pos==sz(s)) return this->words;
		else {
			int c = s[pos]-start;
			if (this->edges[c] == nullptr) return 0;
			else return this->edges[c]->countword(s,pos+1)
		}
	}
	int countprefix(string& p,int pos) {
		if (pos==sz(s)) return this->prefixes;
		else {
			int c = p[pos] - start;
			if (this->edges[c] == nullptr) return 0;
			else return this->edges[c]->countprefix(p,pos+1);
		}
	}
};
