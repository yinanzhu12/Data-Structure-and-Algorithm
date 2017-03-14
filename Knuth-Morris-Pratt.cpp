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
#define lop(i,a,b) for (int i=a; i<=b; i++)
#define vlop(i,v) lop(i,0,sz(v)-1)
#define vlop1(i,v) lop(i,1,sz(v)-1)
#define rlop(i,a,b) for (int i=b; i>=a; i--)
#define vrlop(i,v) rlop(i,0,sz(v)-1)
#define vrlop1(i,v) rlop(i,1,sz(v)-1)
#define printv(i,v) vlop(i,v)cout<<v[i]<<" "
#define all(s) (s).begin(),(s).end()
#define isthere(c,x) ((c).find(x) != (c).end()) 
#define pb push_back
#define enter cout<<'\n'

void failure(vi& f, string& s) {
	vlop1(i, s) {
		int t = f[i-1];
		while (true) {
			if (s[i] == s[t]) {
				f[i]=t+1;
				break;
		}
			else if(!t){
				f[i]=0;
				break;
			}
			else t = f[t-1];
		}

	}
	return;
}

void dfs(matrix(int)& alist, int root, vi& count, vi& subtreesum) {
	vlop(i, alist[root]) {
		dfs(alist, alist[root][i], count,subtreesum);
		subtreesum[root]+=subtreesum[alist[root][i]];
	}
	subtreesum[root]+=count[root];
	return;
}

int main(){
	string s;
	vi f(sz(s));
	f[0]=0;
	/*compute failure function, s start from index 0
	f[i] is the maximum LENGTH the suffix ending in s[i] can be realized as prefix, EXCEPT the string (s[0]...s[i]) itself*/
	failure(f, s);
	vlop(i,f)count[f[i]]++;
	/*build a DIRECTED tree rooted at 0, with vertice 0...sz(s), edge f[i]->i*/
	matrix(int) alist(sz(s)+1);
	vlop(i,f) alist[f[i]].pb(i+1);
	/*subtreesum[i]+1 will be the time s[0]...s[i-1] appears in s as a substring*/
	dfs(alist,0,count,subtreesum);
	/*this procedure find all the t such that (s[0]...s[t-1]) can be realized as a suffix ending at s[u], 
	the initial value of t=u+1 should be INCLUDED*/
        int u, t=u+1;
	while(t)t=f[t-1];
}
