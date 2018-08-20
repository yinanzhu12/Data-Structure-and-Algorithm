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
	void add(string& s,int pos=0) {
		if (pos==sz(s)) {
			words += 1;
			return;
		}
		this->prefixes += 1;
		int c = s[pos] - start;
		if (edges[c] == nullptr) edges[c] = new trie;
		edges[c]->add(s,pos+1);
		return;
	}
	int countword(string& s,int pos=0) {
		if (pos==sz(s)) return words;
		else {
			int c = s[pos]-start;
			if (edges[c] == nullptr) return 0;
			else return edges[c]->countword(s,pos+1)
		}
	}
	int countprefix(string& p,int pos=0) {
		if (pos==sz(p)) return prefixes;
		else {
			int c = p[pos] - start;
			if (edges[c] == nullptr) return 0;
			else return edges[c]->countprefix(p,pos+1);
		}
	}
};

void dfs(trie* tr){
    vlop(i,tr->edges){
        if(tr->edges[i]!=nullptr)dfs(tr->edges[i],prefcount,querrycount);
    }
    return;
}
